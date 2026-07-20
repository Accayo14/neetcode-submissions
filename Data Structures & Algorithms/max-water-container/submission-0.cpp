class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAmt = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                maxAmt = max(maxAmt, min(heights[i], heights[j])*(j-i));
            }
        }

        return maxAmt;
    }
};
