class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p= head, *q = head;
        while(p->next != NULL){
            p = p->next;
            if(p->next != NULL)
                p = p->next;
            q = q->next;
        }
        
        return q;
    }
};

TC - O(N)
SC - O(1)
