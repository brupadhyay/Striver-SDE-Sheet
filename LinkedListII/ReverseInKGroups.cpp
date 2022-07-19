class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode (0);
        dummy -> next = head;
        ListNode* pre = dummy, *cur = dummy, *nxt = dummy;
        
        int len = 0;
        while( cur->next != NULL){
            cur = cur -> next;
            len++;
        }
        while( len >= k){
            cur = pre -> next;
            nxt = cur -> next;
            for(int i=1;i<k;i++){
                cur -> next = nxt -> next;
                nxt -> next = pre -> next;
                pre -> next = nxt;
                nxt = cur -> next;
            }
            pre = cur;
            len -= k;
        }
        return dummy->next;
    }
};

TC - O(N)
SC - O(1)  
