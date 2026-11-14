class Solution {
public:

    long long next_idx(long long current , vector<int>&power){
        long long val = power[current];

        int idx =upper_bound(power.begin(),power.end(),val + 2)-power.begin();

        if(idx == power.size())return -1;

        return idx;
    }

    long long sum1(long long cur,vector<int>&power){


        int idx = upper_bound(power.begin(),power.end(),power[cur])-power.begin();
        int rep= idx-cur;

        return (long long)rep*power[cur];
    }
    vector<long long>dp;
    long long mx(long long i,vector<int>& power){

        if(i>=power.size())return 0;
        if(i==-1)return 0;

        if(dp[i]!=-1)return dp[i];
        long long leave = mx(i+1,power);

        long long next_index = next_idx(i,power);
        long long j=i+1;
        long long sum=power[i];

        long long summ = sum1(i,power);
        long long take = summ + mx(next_index,power);

        return dp[i]=max(leave,take);
    }
    long long maximumTotalDamage(vector<int>& power) {


        dp.assign(power.size(),-1);

        sort(power.begin(),power.end());

        return mx(0,power);
    }
};