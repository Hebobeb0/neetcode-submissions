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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())return nullptr;
        ListNode* res = lists[0];
        lists.erase(lists.begin());
        while(lists.size()){
            ListNode* n1 = lists[0], *n2=res;
            ListNode* curr;
            if(n1->val<n2->val){
                    curr=n1;
                    n1=n1->next;
                }
                else{
                    curr=n2;
                    n2= n2->next;
                }
            res = curr;
            lists.erase(lists.begin());
            while(n1&&n2){
                if(n1->val<n2->val){
                    curr->next = n1;
                    curr = n1;
                    n1=n1->next;
                }
                else{
                    curr->next = n2;
                    curr = n2;
                    n2= n2->next;
                }
                
            }
            if(n1) curr->next = n1;
            else if(n2) curr->next = n2;
        }
        return res;
    }
};
