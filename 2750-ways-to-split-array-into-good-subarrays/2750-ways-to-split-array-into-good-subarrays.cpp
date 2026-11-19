class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        int n = nums.size();
        int l =-1 , r = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1&&l==-1){
                l = i; 
            }

            if(nums[i]==1){
                r = i;
            }
        }

        if(l==-1)return 0;
        // cout<<l<<" "<<r<<"\n";
        long long res = 1;
        for(int i=l;i<=r;){
            
            int j = i;

            while(j<n&&nums[j]==1){
                j++;
            }


            int cnt =0;
            while(j<n && nums[j]==0){
                cnt ++;
                j++;
            }

            if(j<n&&nums[j]==1)
            res = (long long)(res * (cnt+1)) % 1000000007;

            i = j;
        }
     return (int)res;   
    }
};