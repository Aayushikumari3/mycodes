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
//     ListNode* rev(ListNode* head)
//     {
//       ListNode*  pre=NULL;        
// ListNode* front=NULL;
//         while(head->next!=NULL)
//         {
//           front=head->next;
//             head->next=pre;
//             pre=head;
//             head=front;
//         }
//         return pre;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(!head || !head->next)
//         {
//             return true;
//         }
//         ListNode* slow=head;
//          ListNode* fast=head;
//         while(fast->next!=NULL || fast->next->next!=NULL)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
            
//         }
//         slow->next=rev(slow->next);
//         slow=slow->next;
//         while(slow!=NULL)
//         {
// if(head->val!=slow->val)
//             return false;
        
//         head=head->next;
//         slow=slow->next;
//         }
//     return true;
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
    ListNode* rev(ListNode* head)
    {
        ListNode* prev = nullptr;        
        ListNode* next = nullptr;
        
        while (head != nullptr)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the middle of the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        slow = rev(slow);
        ListNode* secondHalf = slow;

        // Compare the first half with the reversed second half
        while (slow != nullptr) {
            if (head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};
