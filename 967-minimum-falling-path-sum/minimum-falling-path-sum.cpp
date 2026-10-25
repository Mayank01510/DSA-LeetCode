class Solution {
public:

    int path(vector<vector<int>>& matrix , int n , int m , int r , int c , vector<vector<int>>& dp){
        if(r == n-1)return matrix[r][c];

        if(dp[r][c] != -1)return dp[r][c];

        int x = INT_MAX;
        int y = INT_MAX;
        int z = INT_MAX;

        if(c-1 >= 0) x = path(matrix , n , m , r+1 , c-1 , dp );
        y = path(matrix , n , m , r+1 , c , dp );
        if(c+1 < m) z = path(matrix , n , m , r+1 , c+1 ,dp );

        return dp[r][c] = matrix[r][c] + min(x , min(y , z));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>dp(m,0);

        for(int i = 0;i<m;i++)dp[i] = matrix[0][i];

        for(int i = 1;i<n;i++){
            vector<int>temp(m,0);
            for(int j = 0;j<m;j++){
                int x = INT_MAX;
                int y = INT_MAX;
                int z = INT_MAX;

                if(j-1 >= 0) x = dp[j-1] + matrix[i][j];
                y = dp[j] + matrix[i][j];
                if(j+1 < m) z = dp[j+1] + matrix[i][j];

                temp[j] =  min(x , min(y , z));
            }
            dp = temp;
        }
        int minsum = dp[0];
        for(int i = 0;i<m;i++){
            minsum = min(minsum,dp[i]);
        }
        return minsum;
    }
};