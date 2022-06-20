Time Complexity: O(N) 

Space Complexity:O(1)


Optimal ->
  class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int maxi = nums[0];
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            if( sum > maxi)
            {
                maxi = sum;
            }
            if( sum < 0 ) sum = 0;
        }
        return maxi;
    }
}


Other one->
  class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //dynamically done with Kadane's algo
        int local_max = 0;
        int global_max = INT_MIN;
        
        for(int i=0; i < nums.size(); i++){
            local_max = max(nums[i],nums[i]+local_max);
            global_max = max(global_max,local_max);
        }
        return global_max;
    }
};
