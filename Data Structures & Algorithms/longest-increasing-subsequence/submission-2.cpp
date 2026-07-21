class Solution {
public:
    int check(vector<int>& nums, int i, int prev, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];

        int steps = check(nums, i+1, prev, dp);
        
        int prevIdx = prev - 1;
        if (prevIdx == -1 || nums[i] > nums[prevIdx]) {
            steps = max(steps, 1 + check(nums, i + 1, i + 1, dp));
        }

        return dp[i][prev] = steps;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return check(nums, 0, 0, dp);
    }
};
