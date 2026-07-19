class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numzeros = 0;
        int prod = 1;

        for(int num: nums){
            if(num == 0) numzeros++;
            else prod *= num;
        }

        if(numzeros > 1){
            vector<int> res(nums.size(), 0);
            return res;
        }

        vector<int> res;
        for(int num: nums){
            if(numzeros == 1){
                if(num == 0) res.push_back(prod);
                else res.push_back(0);
            }
            else res.push_back(prod/num);
        }

        return res;
    }
};
