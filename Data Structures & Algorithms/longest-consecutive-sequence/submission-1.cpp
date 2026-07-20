class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;

        for(int num: nums) st.insert(num);

        int maxlen = INT_MIN;

        for(int num: nums){
            if(st.find(num - 1) != st.end()) continue;

            int len = 0;
            while(st.find(num) != st.end()){
                len++;
                num++;
            }

            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};
