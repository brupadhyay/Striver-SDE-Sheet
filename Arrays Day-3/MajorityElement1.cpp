Solution 1 (Brute Force):

Check the count of occurrences of all elements of the array one by one. Start from the 
first element of the array and count the number of times it occurs in the array. 
If the count is greater than the floor of N/2 then return that element as the answer.
If not, proceed with the next element in the array and repeat the process.

Time Complexity: O(N^2) 

Space Complexity: O(1)
  
Solution 2 (Better):  
Using Hashmap

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int hash[2400] = {0};
        int n = nums.size()/2;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) continue;
            hash[ nums[i] ]++; 
        }
        int ans = 0;
        for(int i=0;i<2400;i++){
            if( hash[i] > n)
                ans = i;
        }
        return ans;
    }
};
Time Complexity: O(N)-> Frequency array or O(N log N) -> HashMap 

Space Complexity: O(N)


Solution 3 (Optimal):

Moore’s Voting Algorithm

Intuition: The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

Majority element count = N/2 + x;

Minority/Other elements = N/2 – x;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = 0;
        
        for(int i:nums){
            if(count == 0){
                element = i;
            }
            if( i == element ) count+=1;
            else count -= 1;
        }
        return element;
    }
};

Time Complexity: O(N)

Space Complexity: O(1)

