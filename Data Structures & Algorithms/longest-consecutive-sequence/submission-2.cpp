class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int num: nums) st.insert(num);

        int maxlen = 0;

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
