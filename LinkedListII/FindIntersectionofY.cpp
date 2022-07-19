class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if( headA == NULL || headB == NULL) return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while( a != b){
            a = a == NULL ? headB : a -> next;
            b = b == NULL ? headA : b -> next;
        }
        return a;
    }
};


Time Complexity: O(2*max(length of list1,length of list2))

Reason: Uses the same concept of difference of lengths of two lists.

Space Complexity: O(1)

Reason: No extra data structure is used
