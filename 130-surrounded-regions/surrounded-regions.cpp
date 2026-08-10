class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visit(m,vector<int>(n,0));
        queue<pair<int,int>>q;

        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O'){
                visit[i][0] = 1;
                q.push({i,0});
            }
            if(board[i][n-1] == 'O'){
                visit[i][n-1] = 1;
                q.push({i,n-1});
            }
        }
        for(int i = 1;i<n-1;i++){
            if(board[0][i] == 'O'){
                visit[0][i] = 1;
                q.push({0,i});
            }
            if(board[m-1][i] == 'O'){
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
                if(row >=0 && col >=0 && row<m && col<n && !visit[row][col] && board[row][col] == 'O' ){
                    visit[row][col] = 1;
                    q.push({row,col});
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'O' && visit[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }
};