class AuthenticationManager {
private:
int timeToLive;
unordered_map<string,int> db;
public:

    AuthenticationManager(int _timeToLive) {
        timeToLive = _timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        db[tokenId]= currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if(db.contains(tokenId)){
            if(db[tokenId] > currentTime){
                db[tokenId] = currentTime + timeToLive;
            }

        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto & [a , b]:db){
            if(b > currentTime){
                cnt++;
            }
        }

        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */