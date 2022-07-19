class Solution {
    
public:
    void deleteNode(ListNode* node) {
        
        node -> val = node->next->val; 
        //delete not possible hence make same to next val
        node->next = node->next->next; //just skip one next position
    }
};

TC & SC - O(1)
