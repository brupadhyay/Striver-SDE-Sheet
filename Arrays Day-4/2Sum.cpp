Solution 1: Naive Approach (Brute Force)
  
Time Complexity - O(N^2)
Space Complexity - O(1)
  
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
   	 for (int j = i + 1; j < nums.size(); ++j) {
   		 if (nums[i] + nums[j] == target) {
   			 res.emplace_back(i);
   			 res.emplace_back(j);
   			 break;
   		 }
   	 }
   	 if (res.size() == 2)
   		 break;
    }
    return res;
} 

Solution 2: Two-Pointer Approach
vector<int> twoSum(vector<int>& nums, int target) {

    	vector<int> res,store;
    	store = nums;

    	sort(store.begin(), store.end());

    	int left=0,right=nums.size()-1;
    	int n1,n2;

    	while(left<right){
        	if(store[left]+store[right]==target){

            	n1 = store[left];
            	n2 = store[right];

            	break;

        	}
        	else if(store[left]+store[right]>target)
            	    right--;
        	else
            	    left++;
    	}

    	for(int i=0;i<nums.size();++i){

        	if(nums[i]==n1)
            	    res.emplace_back(i);
        	else if(nums[i]==n2)
            	    res.emplace_back(i);
    	}

    	    return res;
	}
  
Time Complexity: O(NlogN)

Space Complexity: O(N)
  
Solution 3: Hashing (Most efficient)

Approach: We can solve this problem efficiently by using hashing. We’ll use a hash-map to see
if there’s a value target – i that can be added to the current array value i to get the sum equals to target.
  If target – i is found in the map, we return the current index, and index stored at target – nums[index] location in the map. 

This can be done in constant time.
  
 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mpp;
        
        for(int i=0; i<nums.size();i++)
        {
            if( mpp.find(target - nums[i]) != mpp.end())
            {
                cout << i;
                res.emplace_back(mpp[target-nums[i]]);
                res.emplace_back(i);
                break;
            }
            mpp[nums[i]] = i;            
        }
        return res;
    }
};

Time Complexity: O(N)

Space Complexity: O(N)
