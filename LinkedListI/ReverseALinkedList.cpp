class Solution {
    
    ListNode* reverse(ListNode* head){
        //base case
        if( head == nullptr || head->next == nullptr ) return head;
        
        ListNode* smallList = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return smallList;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
        
    }
};

Time Complexity:

We move to the end of the list and achieve our reversed list. Thus, the time complexity is O(N) where N represents the number of nodes.
  
Space Complexity:
space complexity is O(1)
