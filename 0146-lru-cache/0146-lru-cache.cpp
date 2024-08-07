// // class LRUCache {
// // public:
// //     LRUCache(int capacity) {
        
// //     }
    
// //     int get(int key) {
        
// //     }
    
// //     void put(int key, int value) {
        
// //     }
// // };

// // /**
// //  * Your LRUCache object will be instantiated and called as such:
// //  * LRUCache* obj = new LRUCache(capacity);
// //  * int param_1 = obj->get(key);
// //  * obj->put(key,value);
// //  */
// class LFUCache {
// public:
//      class Node{
//          public:
//          int key;
//         int val;
//         int freq;
//         Node *next;
//         Node *prev;
//         Node(int key1,int val1){
//             key=key1;
//             val=val1;
//             freq=1;
            
//         }
//      };
//  struct List{
//      int size;
//      Node *head;
//      Node *tail;
//      List(){
//          head=new Node(0,0);
//          tail=new Node(0,0);
//          head->next=tail;
//          tail->prev=head;
//          size=0;
//      }
//      void addFront(Node *node){
//          Node *temp=head->next;
//          node->next=temp;
//          node->prev=head;
//          head->next=node;
//          temp->prev=node;
//          size++;
//      }
//      void removeNode(Node *delnode){
//          Node*delprev=delnode->prev;
//          Node*delnext=delnode->next;
//          delprev->next=delnext;
//          delnext->prev=delprev;
//          size--;
//      }
//  };
 
// map<int,Node*>keyNode;
//     map<int,List*>freqListMap;
//     int maxSizeCache;
//     int minFreq;
//     int curSize;

//     LFUCache(int capacity) {
//          maxSizeCache=capacity;
//          minFreq=0;
//         curSize=0;
//     }
//     void updateFreqListMap(Node* node) {
//         keyNode.erase(node->key);
//         freqListMap[node->freq]->removeNode(node);
//         if(node->freq==minFreq && freqListMap[node->freq]->size==0){
//             minFreq++;
//         }
//         List *nextHigherFreqList=new List();
//         if(freqListMap.find(node->freq+1)!=freqListMap.end()){
//             nextHigherFreqList=freqListMap[node->freq+1];
//         }
//         node->freq+=1;
//         nextHigherFreqList->addFront(node);
//         freqListMap[node->freq]=nextHigherFreqList;
//         keyNode[node->key]=node;
//     }

   
//     int get(int key) {
//         if (keyNode.find(key) != keyNode.end()) {
//             Node* node=keyNode[key];
//             int val=node->val;
//             updateFreqListMap(node);
//             return val;
//         }
//         return -1;
      
//     }
    
//     void put(int key, int value) {
//             if (maxSizeCache == 0) return;

//         if (keyNode.find(key) != keyNode.end()) {
//             Node* node = keyNode[key];
//             node->val = value;
//             updateFreqListMap(node);
//         } else {
//             if (maxSizeCache == curSize) {
//                List *list=freqListMap[minFreq];
//                 keyNode.erase(list->tail->prev->key);
//                 freqListMap[minFreq]->removeNode(list->tail->prev);
//                 curSize--;
//             }
//             curSize++;
//             minFreq=1;
//             List *listFreq=new List();
//             if(freqListMap.find(minFreq)!=freqListMap.end()){
//                 listFreq=freqListMap[minFreq];
//             }
//             Node *node=new Node(key,value);
//             listFreq->addFront(node);
//             keyNode[key]=node;
//             freqListMap[minFreq]=listFreq;
//         }
//     }
    
// };
#include <unordered_map>
#include <set>
#include <utility>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), timestamp(0) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        
        // Update the access time
        usage.erase({it->second.second, key});
        it->second.second = ++timestamp;
        usage.insert({it->second.second, key});
        
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Update the value and access time
            usage.erase({it->second.second, key});
            it->second = {value, ++timestamp};
            usage.insert({timestamp, key});
        } else {
            // Insert new key-value pair
            if (cache.size() == capacity) {
                // Remove the least recently used item
                auto lru = *usage.begin();
                cache.erase(lru.second);
                usage.erase(usage.begin());
            }
            cache[key] = {value, ++timestamp};
            usage.insert({timestamp, key});
        }
    }

private:
    int capacity;
    int timestamp;
    std::unordered_map<int, std::pair<int, int>> cache; // key -> {value, timestamp}
    std::set<std::pair<int, int>> usage; // {timestamp, key} sorted by timestamp
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */