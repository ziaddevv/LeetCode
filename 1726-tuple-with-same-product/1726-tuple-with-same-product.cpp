class Solution {
public:
    // int combination(int n, int r) {
    //     if (r < 0 || r > n)
    //         return 0;
    //     if (r == 0 || r == n)
    //         return 1;

    //     if (r > n - r) {
    //         r = n - r;
    //     }

    //     int result = 1;
    //     for (int i = 1; i <= r; ++i) {
    //         result *= (n - r + i);
    //         result /= i;
    //     }

    //     return result;
    // }


    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int, int> m;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+ 1; j < nums.size(); j++) {
                if (i == j)
                    continue;

                res += m[nums[i]*nums[j]]*8;
                m[nums[i] * nums[j]]++;

            }
        }

        // for (auto i : m) {
        //     // cout << i.first << " " << i.second << "\n";
        //     res += combination(i.second, 2) * 8;
        // }

        return res;
    }
};