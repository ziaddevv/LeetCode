class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int sum = 0;
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            sum += reward2[i];
            diff[i] = reward1[i] - reward2[i];
        }

        sort(diff.rbegin(), diff.rend());

        for (int i = 0; i < k; i++) {
            sum += diff[i];
        }

        return sum;
    }
};
