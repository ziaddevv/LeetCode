class Solution {
public:
    long long maximumTotalSum(vector<int>& max_h) {
        long long res=0;

        sort(max_h.rbegin(),max_h.rend());
        int n=max_h.size();
        int lst =max_h[0];
        res += max_h[0];

        cout<<lst;
        for(int i=1;i<n;i++){
            int a = max_h[i];

            if(a < lst){
                res += a;
                lst = a;
            }else if(a >= lst){
                res += lst -1;
                lst -- ;
            }

            if (lst == 0 )return -1;
        }

        return res;
    }
};