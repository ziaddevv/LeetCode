class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        

        // just to handle the long input 10^9 in case of k=1
        if(k==1){
            return r-l+1;
        }



        int i=0;
        int cnt=0;
        int p = pow(i , k);
        while(p <= r){

            if(p>=l && p <= r){
                cnt++;
            }

            i++;
            p=pow(i,k);
        }

        return cnt;
    }
};