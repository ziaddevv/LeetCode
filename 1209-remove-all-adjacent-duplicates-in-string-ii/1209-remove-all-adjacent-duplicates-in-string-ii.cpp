class Solution {
public:

    string fromStack(stack<pair<char, int>> &st){
        string res;

        while(st.size()>0){
            res.push_back(st.top().first);
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push({s[i], 1});
            } else {
                if (st.top().first == s[i]) {
                    st.push({s[i], st.top().second + 1});
                } else {
                    st.push({s[i], 1});
                }
            }
            if (st.size() > 0 && st.top().second == k) {
                int tmp = k;
                while (st.size() > 0 && tmp > 0) {
                    st.pop();
                    tmp--;
                }
            }
        }


        string res =  fromStack(st);

        return res;
    }
};