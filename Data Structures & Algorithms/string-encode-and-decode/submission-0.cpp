class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for(string str: strs){
            int len = str.length();
            encoded += to_string(len) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        int n = s.length();
        vector<string> res;

        while(i < n){
            int j = i;
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + len;

            res.push_back(s.substr(i, len));

            i = j;
        }

        return res;
    }
};
