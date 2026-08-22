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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        ListNode* node = head;
        while(node->next) {
            node = node->next;
            ++len;
        }
        node =head;
        if(n==len){
            return head->next;
        }
        for(int i = 1;i<len-n;i++){
            node=node->next;
        }
        node->next = node->next->next;
        return head;
    }
};
