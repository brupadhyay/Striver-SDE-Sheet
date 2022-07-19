class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if( head == NULL || head->next == NULL ) return false;
        
        ListNode* tortoise = head;
        ListNode* rabbit = head;
        
        while( tortoise != NULL && rabbit != NULL)
        {
            rabbit = rabbit -> next ;
            if( rabbit != NULL){
                rabbit = rabbit -> next ;
            }
            tortoise = tortoise -> next;
            
            if( tortoise == rabbit ){
                return true;
                break;
            }
            
        }
        return false;
        
    }
};

TC - O(N)
SC - O(1)  
