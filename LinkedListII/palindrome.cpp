class Solution {
    ListNode* getMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while( fast->next!=NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow -> next;
    }
    return slow;
}
ListNode* reverse(ListNode* pointer){
    ListNode* pre = NULL;
    ListNode* cur = pointer;
    ListNode* nex = NULL;
    while( cur != NULL){
        nex = cur -> next ;
        cur -> next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}
public:
    bool isPalindrome(ListNode* head) {
        // Write your code here.
    if( head == NULL || head ->next == NULL) return true;
    ListNode* mid = getMiddle (head);
    
    mid -> next = reverse(mid->next);
    ListNode* dummy = head;
    ListNode* newNode = mid->next;
    
    while(newNode!=NULL){
        if(dummy->val != newNode->val) return false;
        newNode = newNode->next; 
        dummy = dummy ->next;
    }
    
    return true;
    }
};


Time Complexity: O(N/2)+O(N/2)+O(N/2)

Reason: O(N/2) for finding the middle element, reversing the list from the middle element, and traversing again to find palindrome respectively.

Space Complexity: O(1)

Reason: No extra data structures are used.

