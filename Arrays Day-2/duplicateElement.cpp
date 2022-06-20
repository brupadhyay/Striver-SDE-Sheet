Time complexity: O(N). Since we traversed through the array only once.

Space complexity: O(1).

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[ nums[fast] ];
        }while( slow!=fast);
        
        fast = nums[0];
        while( slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
