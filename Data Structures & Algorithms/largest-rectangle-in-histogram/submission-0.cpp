class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftmost(n, -1);
        vector<int> rightmost(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) leftmost[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) rightmost[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, heights[i] * (rightmost[i] - leftmost[i] - 1));
        }

        return maxArea;
    }
};
