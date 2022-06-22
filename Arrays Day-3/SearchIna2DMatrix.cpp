Brute Force - TC-> O(m*n)  SC-> O(1)
  
 
Optimal Approach - TC -> O(log(m*n))  SC->O(1)
  


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        /*Optimal Approach Because Binary Search
            TC-> O(log(m*n))  */
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m*n-1;
        int mid = low+(high-low)/2;
        while(low<=high){
        
            int element = matrix[mid/n][mid%n];
            if( element == target){
              return true;
            }
            else if( element > target){
             high = mid-1;
            }
            else low=mid+1;
        
            mid = low+(high-low)/2;
        }
      return false;
     }
};
