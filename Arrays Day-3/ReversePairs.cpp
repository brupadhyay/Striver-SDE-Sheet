Solution 1: Brute Force Approach

Intuition : 

As we can see from the given question that i < j, So we can just use 2 nested loops and check for the given condition which is arr [i] > 2* arr[j].
  
  
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( nums[i] > 2*nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

TC -> O(n^2)
SC -> O(1)

Solution 2: Optimal Solution (Using Merge_sort)

Intuition:

-> We will be using the Merge Sort Algorithm to solve this problem. We split the whole array into 2  parts creating a Merge Sort Tree-like structure.
  During the conquer step we do the following task : 

-> We take the left half of the Array and Right half of the Array, both are sorted in themselves. 

-> We will be checking the following condition arr[i] <= 2*arr[j]  where i is the pointer in the Left Array and j is the pointer in the Right Array. 

-> If at any point arr[i] <= 2*arr[j] , we add 1  to the answer as this pair has a contribution to the answer. 

-> If Left Array gets exhausted before Right Array we keep on adding the distance j pointer traveled as both the 
arrays are Sorted so the next ith element from Left Subarray will equally contribute to the answer.


class Solution {
    
    int merge(vector<int> &nums, int s, int mid, int e){
        int j=mid;
        int total = 0;
        for(int i=s ; i<=mid-1 ; i++){
            while( j<=e && nums[i] > 1LL*2*nums[j]){
                j++;
            }
            total += (j - mid);
        }
        vector<int> t;
        int left = s, right = mid;
        
        while(left<=mid-1 && right<=e){
            if(nums[left]<=nums[right]){
                t.push_back( nums[left++]);
                
            }
            else t.push_back(nums[right++]);
        }
        while( left<=mid-1){
            t.push_back( nums[left++]);
        }
        while( right<=e){
            t.push_back( nums[right++]);
        }
        
       for (int i = s; i <= e; i++) {
         nums[i] = t[i - s];
        }
        
        return total;
        
    }
    
    int mergeSort(vector<int> &nums, int s, int e){
        if(s>=e) return 0;
        int mid  = s+(e-s)/2;
        int inv_cnt = 0;
        inv_cnt += mergeSort(nums,s,mid);
        inv_cnt += mergeSort(nums,mid+1,e);
        
        inv_cnt += merge(nums,s,mid+1,e);
        
        return inv_cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mergeSort(nums,0,n-1);
        return ans;
    }
};


Time Complexity : O( N log N ) + O (N) + O (N)   

Reason : O(N) – Merge operation , O(N) – counting operation ( at each iteration of i , j doesn’t start from 0 . Both of them move linearly ) 

Space Complexity : O(N) 

Reason : O(N) – Temporary vector
