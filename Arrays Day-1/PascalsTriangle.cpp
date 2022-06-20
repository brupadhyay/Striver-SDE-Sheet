Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(numRows2).

Space Complexity: Since we are creating a 2D array, space complexity = O(numRows2).
  
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > r(numRows);
        for(int i=0; i<numRows; i++){
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;
            
            for(int j=1; j<i ; j++){
                r[i][j] = r[i-1][j-1] + r[i-1][j]; 
            }
        }
        return r;
    }
};
