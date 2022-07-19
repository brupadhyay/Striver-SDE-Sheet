class Solution {
    ListNode* floydCycle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast->next != NULL && fast->next->next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if( fast == slow){
                return fast;
            }
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if( head == NULL || head-> next == NULL) return NULL;
        
        ListNode* intersection = floydCycle(head);
        if( intersection == NULL) return NULL;
        ListNode* slow = head;
        while( slow != intersection){
            slow = slow -> next;
            intersection = intersection -> next;
        }
        return slow;
    }
};

Time Complexity: O(N)

Reason: We can take overall iterations and club them to O(N)

Space Complexity: O(1)

Reason: No extra data structure is used.
