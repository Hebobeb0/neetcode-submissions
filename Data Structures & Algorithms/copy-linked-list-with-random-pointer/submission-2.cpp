/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* start = head;
        Node* nhead = new Node(head->val);
        Node* nstart = nhead;
        unordered_map<Node*,Node*> mp;
        mp[start] = nstart;
        mp[nullptr] = nullptr;
        while(head->next){
            head=head->next;
            Node* nNext = new Node(head->val);
            nhead->next = nNext;
            nhead = nNext; 
            mp[head]=nhead;
        }
        head = start;
        nhead = nstart;
        while(head){
            nhead->random = mp[head->random];
            nhead = nhead->next;
            head = head->next;
        }
        return nstart;
        }
};
