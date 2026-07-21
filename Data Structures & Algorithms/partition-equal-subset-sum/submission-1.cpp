class Solution {
public:
    bool check(vector<int>& nums, int idx, int tgt, vector<vector<int>>& dp){
        if(tgt == 0) return true;
        if(tgt < 0) return false;
        if(idx == nums.size()) return false;

        if(dp[idx][tgt] != -1) return dp[idx][tgt];

        return dp[idx][tgt] = check(nums, idx+1, tgt, dp)||check(nums, idx+1, tgt-nums[idx], dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;

        if(sum%2 == 1) return false;

        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));

        return check(nums, 0, target, dp);
    }
};
