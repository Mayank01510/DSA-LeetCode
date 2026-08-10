class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int visit[m][n];
        vector<vector<int>>ans (m , vector<int>(n));
        queue<pair<pair<int,int>,int>>q;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visit[i][j] = 1;
                }
                else visit[i][j] = 0;
            }
        }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            ans[r][c] = d;
            for(int i = 0;i<4;i++){
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row<m && row>=0 && col >=0 && col < n && mat[row][col] == 1 && !visit[row][col]){
                    visit[row][col] = 1;
                    q.push({{row,col},d+1});
                }
            }
        }
        return ans;
    }
};