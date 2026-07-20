class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracket;
        bracket[')'] = '(';
        bracket['}'] = '{';
        bracket[']'] = '[';

        stack<char> st;

        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);

            else{
                if(st.empty() == true) return false;

                char open = st.top();
                st.pop();

                if(bracket[ch] == open) continue;
                else return false;
            }
        }

        if(st.empty()) return true;
        else return false;
    }
};
