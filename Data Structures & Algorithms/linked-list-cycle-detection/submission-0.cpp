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
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* ptr1=head,*ptr2=head->next;
        while(true){
            if(ptr2 == nullptr||ptr2->next == nullptr) return false;
            if(ptr1 == ptr2 || ptr1 == ptr2->next) return true;
            ptr2 = ptr2->next->next;
            ptr1=ptr1->next;

        }

    }
    
};
