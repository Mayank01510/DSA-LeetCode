class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int drow[] = {0,1,0,-1,-1,1,-1,1};
        int dcol[] = {1,0,-1,0,-1,1,1,-1};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        if(grid[0][0] == 1 || grid[n-1][n-1])return-1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(row == n-1 && col == n-1)return d;

            for(int i = 0;i<8;i++){
                int r = row + drow[i];
                int c = col + dcol[i];
                if(r<n &&c<n && r>=0 && c>=0 && dis[r][c] == INT_MAX && grid[r][c] == 0){
                    dis[r][c] = d+1;
                    q.push({d+1,{r,c}});
                }
            }
        }
        return -1;
    }
};