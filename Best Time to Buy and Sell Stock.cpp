class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int profit(0);
        int lowestSoFar(INT_MAX);
        for(int price : prices) {
            profit = max(profit, price - lowestSoFar);
            lowestSoFar = min(lowestSoFar, price);
        }
        return profit;
    }
};