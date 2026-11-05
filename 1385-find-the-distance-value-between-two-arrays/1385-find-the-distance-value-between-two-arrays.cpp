class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int n = arr1.size();
        int m = arr2.size();

        sort(arr2.begin(), arr2.end());

        int cnt=0;
        for (int i = 0; i < n; i++) {
            int lower_idx =
                lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();

            // only check the before element
            int closest = -1;
            if (lower_idx == m) {
                closest = arr2[m - 1];
            } else {
                closest = arr2[lower_idx];

                if (lower_idx != 0) {
                    if (abs(arr2[lower_idx] - arr1[i]) >
                        abs(arr2[lower_idx - 1] - arr1[i])) {
                        closest = arr2[lower_idx - 1];
                    }
                }
            }

            if(abs(closest - arr1[i])>d){
                cnt++;
            }
        }

        return cnt;
    }
};