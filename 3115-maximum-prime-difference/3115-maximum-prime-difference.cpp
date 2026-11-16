class Solution {
public:
    bool isPrime(int a){

        if(a==1)return false;
        for(int i=2;i<=sqrt(a);i++){
            if(a%i==0){
                return false;
            }
        }

        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int first = -1;
        int last = -1;
        for(int i=0;i<n;i++){
            if(isPrime(nums[i])){
                if(first == -1){
                    first = i;
                }
                last = i;
            }
        }

        return last - first;
    }
};