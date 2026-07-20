class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAmt = 0;
        int n = heights.size();

        int left = 0, right = n - 1;

        while(left < right){
            maxAmt = max(maxAmt, min(heights[left], heights[right])*(right-left));

            if(heights[left] < heights[right]) left++;
            else right--;
        }

        return maxAmt;
    }
};