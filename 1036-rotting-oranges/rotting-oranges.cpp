class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visit[n][m];
        queue<pair<pair<int,int>,int>>q ;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visit[i][j] = 2;
                }
                else visit[i][j] = 0;
            }
        }

        int time  = 0;
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int i = 0;i<4;i++){
                int dr = r + drow[i];
                int dc = c + dcol[i];
                if(dc >=0 && dr >=0 && dc < m && dr < n &&
                grid[dr][dc] == 1 && !visit[dr][dc]){
                    q.push({{dr,dc},t+1});
                    visit[dr][dc] = 1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && visit[i][j] == 0)return -1;
            }
        }

        return time;
    }
};