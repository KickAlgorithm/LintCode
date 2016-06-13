class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int profit(0);
        for(int i = 0;i < (int)prices.size() - 1;i++) {
            int temp = prices[i+1] - prices[i];
            if(temp > 0) profit += temp;
        }
        return profit;
    }
};