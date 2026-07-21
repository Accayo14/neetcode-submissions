class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = nums[0];

        while(l <= r){
            if(nums[l] < nums[r]){
                ans = min(ans, nums[l]);
                break;
            }
            
            int m = l + (r-l)/2;
            ans = min(ans, nums[m]);

            if(nums[m] >= nums[l]) l = m + 1;
            else r = m - 1;

        }

        return ans;
    }
};
