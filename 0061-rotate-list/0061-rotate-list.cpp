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
// #include <deque>

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (head == nullptr || k == 0) return head;

//         std::deque<int> q;
//         ListNode* temp = head;
//         int len = 0;

//         // Push all the values of the list into the deque
//         while (temp != nullptr) {
//             q.push_back(temp->val);
//             temp = temp->next;
//             len++;
//         }

//         // Reduce k to a manageable number
//         k = k % len;
//         if (k == 0) return head;

//         // Rotate the deque k times to the right
//         for (int i = 0; i < k; i++) {
//             int g = q.back();
//             q.pop_back();
//             q.push_front(g);
//         }

//         // Create a new list from the deque
//         ListNode* headn = new ListNode(q.front());
//         q.pop_front();
//         ListNode* newHead = headn;

//         while (!q.empty()) {
//             headn->next = new ListNode(q.front());
//             q.pop_front();
//             headn = headn->next;
//         }

//         return newHead;
//     }
// };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases
        if (!head || !head->next || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next) {
            cur = cur->next;
            len++;
        }
        
        // connect the end of the list to the head
        cur->next = head;
        
        // compute the number of rotations needed
        k = k % len;
        k = len - k;
        
        // go to the new end of the list
        while (k--) {
            cur = cur->next;
        }
        
        // make the node head and break the connection
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
