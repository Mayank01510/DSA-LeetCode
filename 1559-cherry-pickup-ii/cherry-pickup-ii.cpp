class Solution {
public:

    int pick(vector<vector<int>>& grid ,int n ,int m , int i ,int j1 ,int j2,vector<vector<vector<int>>>& dp){
        if( j1 < 0 || j1 > m-1 || j2 < 0 || j2 > m-1)return -1e8;

        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];

        if(i == n-1){
            if(j1 == j2)return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        int maxi = 0;

        for(int k = -1;k<2;k++){
            for(int p = -1;p<2;p++){
                if(j1 == j2)maxi = max(maxi,grid[i][j1] + pick(grid,n,m,i+1 , j1+k , j2+p,dp));
                else{
                    maxi = max(maxi,grid[i][j1] + grid[i][j2] + pick(grid , n ,m ,i+1 , j1+k , j2+p,dp));
                }
            }
        }

        return dp[i][j1][j2] = maxi;
    }

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(m, 0))
    );

    for(int j1 = 0; j1 < m; j1++) {
        for(int j2 = 0; j2 < m; j2++) {
            if(j1 == j2)
                dp[n-1][j1][j2] = grid[n-1][j1];
            else
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {

                int maxi = -1e8;

                for(int k = -1; k <= 1; k++) {
                    for(int p = -1; p <= 1; p++) {

                        int nj1 = j1 + k;
                        int nj2 = j2 + p;

                        if(nj1 >= 0 && nj1 < m &&
                           nj2 >= 0 && nj2 < m) {

                            int val = 0;

                            if(j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];

                            val += dp[i+1][nj1][nj2];

                            maxi = max(maxi, val);
                        }
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
    }
};
