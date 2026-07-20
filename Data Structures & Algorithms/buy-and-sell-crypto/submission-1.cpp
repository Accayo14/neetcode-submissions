class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minPrice = prices[0];
        int right = 0;

        while(right < prices.size()){
            maxP = max(maxP, prices[right] - minPrice);
            minPrice = min(minPrice, prices[right]);

            right++;
        }
        return maxP;
    }
};
