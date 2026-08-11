class Solution {
public:

    void dfs(vector<vector<char>>& board , vector<vector<int>>& visit, int drow[] , int dcol[] , int r ,int c){
        visit[r][c] = 1;

        for(int i = 0;i<4;i++){
            int row = r + drow[i];
            int col = c + dcol[i];
            if(row >=0 && col >=0 && row<board.size() && col<board[0].size() && !visit[row][col] && board[row][col] == 'O' ){
                dfs(board , visit , drow , dcol , row , col);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visit(m,vector<int>(n,0));
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};

        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O' && !visit[i][0]){
                dfs(board,visit , drow,dcol,i,0);
            }
            if(board[i][n-1] == 'O' && !visit[i][n-1]){
                dfs(board,visit , drow,dcol,i,n-1);
            }
        }
        for(int i = 1;i<n-1;i++){
            if(board[0][i] == 'O' && !visit[0][i]){
                dfs(board,visit , drow,dcol,0,i);
            }
            if(board[m-1][i] == 'O' && !visit[m-1][i]){
                dfs(board,visit , drow,dcol,m-1,i);
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