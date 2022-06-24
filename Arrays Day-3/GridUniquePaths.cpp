Approach 1 : Using Recursion(Brute)
  
 int countPaths(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }

Time Complexity: The time complexity of this recursive solution is exponential.

Space Complexity: As we are using stack space for recursion so the space complexity will also be exponential.
                               
Better : Dynamically ( Repeat the past) to decrease computation
class Solution {
    int countPaths(int i, int j, int m, int n,vector<vector<int>> &dp)
    {
        if(i==(m-1)&&j==(n-1)) return 1;
        if(i>=m||j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j]=countPaths(i+1,j,m,n,dp)+countPaths(i,j+1,m,n,dp);
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
        
        
    }
};


Time Complexity: O(n*m)
Space Complexity: O(n*m)
  
  
  
Optimal Solution
Using Combinatorics Solution

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = n-1;
        
        double res = 1.0;
        for(int i=1;i<=r;i++){
            res = res*(N-r+i)/i;
        }
        return (int) res;
    }
};

Time Complexity: The time complexity of this solution will be O(n-1) or  O(m-1) depending on the formula we are using.

Space Complexity: As we are not using any extra space the space complexity of the solution will be  O(1).
