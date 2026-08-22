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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode();
        ListNode* node = start;
        int dig=0,res=0;
        dig = l1->val + l2->val +res;
        res = dig/10;
        dig %= 10;
        node->val = dig;
       
       while(l1->next || l2->next){
            ListNode* x = new ListNode();
            node->next = x;
            node = x;
            dig = res;
            if(l1 ->next){
                l1 = l1->next;dig+=l1->val;
            }
            if(l2->next){
                l2 = l2->next; dig+=l2->val;
            }
            res = dig/10;
            dig%=10;
            node->val = dig;
       }
       if(res>0){
        ListNode*x = new ListNode(res);
            node->next = x;
       }
       return start;
        
    }
};
