// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1==nullptr )
//             return list2;
//          if(list2==nullptr)
//             return list1;
//         ListNode* list=nullptr;
//         ListNode* listh=list;
//         while(list1!=nullptr || list2!=nullptr)
//         {
//               if(list1->val>=list2->val)
//               {
               
//                   list->val=list1->val;
//                   list1=list1->next;
//                   list->next=nullptr;
//                   list=list->next;
//               }
        
//         else if(list2->val>=list1->val)
            
//         {
//             list->val=list2->val;
//                   list2=list2->next;
//                   list->next=nullptr;
//                   list=list->next;
//         }
//         }  
//         if(list1==nullptr)
//         {
//             list->next=nullptr;
//             list->next->val=list2->next->val;
//             list2=list2->next;
            
//         }
//          if(list2==nullptr)
//         {
//             list->next=nullptr;
//             list->next->val=list1->next->val;
//             list1=list1->next;  
//         }
//         return listh;
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify edge cases
        ListNode dummy;
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining nodes
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};
