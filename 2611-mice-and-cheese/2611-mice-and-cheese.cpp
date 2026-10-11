class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<pair<int,int>> pq;
        int n= reward1.size();
        for(auto i =0;i<n;i++){

            pq.push({reward1[i]-reward2[i],i});
        }

        set<int> st;

        while(k--){
            st.insert(pq.top().second);
            pq.pop();
        }
        int sum = 0;
        for(int i=0;i<n;i++){

            if(st.find(i)!=st.end()){
                sum+=reward1[i];
            }else{
                sum+=reward2[i];
            }
        }
        return sum;
    }
};