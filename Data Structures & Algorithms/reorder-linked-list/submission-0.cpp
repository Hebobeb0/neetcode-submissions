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
    void reorderList(ListNode* head) {
        if(!head->next) return;
        if(!head->next->next) return;
        ListNode* slow,*fast;
        slow = head;
        fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast = fast->next->next; 
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        slow = nullptr;
        while(second){
            ListNode*tmp = second->next;
            second->next = slow;
            slow = second;
            second = tmp;
        }
        ListNode* first = head;
        second = slow; 
        while(second){
            ListNode* t1 = first->next, *t2 = second->next; 
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
        

        
        
    }
};
