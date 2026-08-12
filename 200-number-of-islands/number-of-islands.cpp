class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visit(m,vector<int>(n,0));
        queue<pair<int,int>>q;

        int islands = 0;

        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        for(int x = 0;x<m;x++){
            for(int y = 0;y<n;y++){
                if(grid[x][y] == '1' && !visit[x][y]){
                    q.push({x,y});
                    islands++;
                }
            
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row >=0 && col >=0 && row<m && col<n && !visit[row][col] && grid[row][col] == '1' ){
                    visit[row][col] = 1;
                    q.push({row,col});
                }
            }
        }
        }
        }
        return islands ; 
    }
};