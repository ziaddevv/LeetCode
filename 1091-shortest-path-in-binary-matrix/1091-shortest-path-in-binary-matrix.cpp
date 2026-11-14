class Solution {
public:


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        queue<array<int,3>>q;
        vector<vector<int>>dir = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0},
            {1,-1},
            {-1,1},
            {1,1},
            {-1,-1},
        };
        vector<vector<bool>>visited(n,vector<bool>(n));
        visited[0][0] = true;

        q.push({0,0,1});

        while(!q.empty()){
            auto [x,y,dist] = q.front();

            q.pop();

            if(x==n-1 && y == n-1)return dist;
            
            for(int d=0;d<8;d++){
                int newX = x + dir[d][0];
                int newY = y + dir[d][1];

                if(newX >=0 && newX <n && newY >=0 &&newY < n&&visited[newX][newY]==false&&grid[newX][newY]==0){
                    visited[newX][newY] = true;
                    q.push({newX , newY,dist+1});
                }
            }

        }


        return -1;

    }
};