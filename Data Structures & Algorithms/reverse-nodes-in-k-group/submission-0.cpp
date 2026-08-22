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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res;
        int n=0;
        ListNode* temp = head;
        while(temp!= nullptr){
            temp = temp->next;
            ++n;
        }
        if (n<k) return head;
        temp = head;
        for(int i=1;i<k;++i){
            temp=temp->next;
        }
        res = temp;
        temp = head;
        ListNode* prev = nullptr, *first = head,*a=head,*b=a->next;
        int c = n;
        while(c>=k){
            c-=k;
            for(int i=1;i<k;i++){
                ListNode* tmp = b->next;
                b ->next = a;a=b;b=tmp;
            }
            if(prev) prev->next = a;
            prev = first;
            first->next = b;
            first = b;
            a=b;
            if(b)b=b->next;
        }

        return res;

    }
};
