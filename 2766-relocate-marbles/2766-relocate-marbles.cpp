class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n = nums.size();
        vector<int>res;

        set<int> st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i =0;i<moveFrom.size();i++){

            int a = moveFrom[i];
            int b = moveTo[i];

            st.erase(a);
            st.insert(b);
        }

        for (auto i : st){
            res.push_back(i);
        }


        return res;

    }
};