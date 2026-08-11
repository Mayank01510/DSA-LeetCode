class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visit(m,vector<int>(n,0));
        queue<pair<int,int>>q;

        for(int i = 0;i<m;i++){
            if(grid[i][0] == 1){
                visit[i][0] = 1;
                q.push({i,0});
            }
            if(grid[i][n-1] == 1){
                visit[i][n-1] = 1;
                q.push({i,n-1});
            }
        }
        for(int i = 1;i<n-1;i++){
            if(grid[0][i] == 1){
                visit[0][i] = 1;
                q.push({0,i});
            }
            if(grid[m-1][i] == 1){
                visit[m-1][i] = 1;
                q.push({m-1,i});
            }
        }

        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row >=0 && col >=0 && row<m && col<n && !visit[row][col] && grid[row][col] == 1 ){
                    visit[row][col] = 1;
                    q.push({row,col});
                }
            }
        }
        int landcount = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && visit[i][j] == 0){
                    landcount++;
                }
            }
        }
        return landcount ;
    }
};