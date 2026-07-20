class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push({temps[i], i});
                continue;
            }

            while(!st.empty() && st.top().first < temps[i]){
                int posn = st.top().second;
                st.pop();

                res[posn] = i - posn;
            }

            st.push({temps[i], i});
        }

        return res;
    }
};
