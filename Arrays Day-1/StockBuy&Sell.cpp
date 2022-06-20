Time Complexity: O(N) 

Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro =0;
        int minPrice = INT_MAX;
        for(int i=0; i< prices.size();i++){
            minPrice= min(minPrice, prices[i]);
            maxPro =max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};
