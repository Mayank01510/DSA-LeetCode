class Solution {
public:

    long long path(int m , int n , int i , int j,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1)return 1;

        if(dp[i][j] != -1)return dp[i][j];

        int l = 0;
        int r = 0;
        if(i+1 < m) l = path(m , n , i+1 , j ,dp);

        if(j+1 < n) r = path(m , n ,i ,j+1 , dp);

        return dp[i][j] = l + r;
    }

    int uniquePaths(int m, int n){
        vector<vector<int>>dp(m ,vector<int>(n,-1));
        dp[0][0] = 1;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j== 0)dp[i][j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i > 0)up = dp[i-1][j];
                    if(j > 0)left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};