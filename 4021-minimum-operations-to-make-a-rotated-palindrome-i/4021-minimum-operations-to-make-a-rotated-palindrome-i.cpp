class Solution {
public:
    string swap(string str) { return str.substr(1) + str[0]; }
    int minOperations(string s) {

        int n = s.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {


            int cnt = 0;

            for (int j = 0; j < n/2; j++) {
                int a = min(s[j], s[n - j - 1]);
                int b = max(s[j], s[n - j - 1]);

                // cout<<a <<" "<<b <<"\n";
                int x = b - a;
                int y = a - b + 26;

                cnt += min(x, y); 
            }
            // cout<<"break\n";

            res = min(res, cnt+i);
            s = swap(s);
        }

        return res;
    }
};