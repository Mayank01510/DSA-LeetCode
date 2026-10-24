class Solution {
public:

    int path(int n , int m , int i , int j ,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if( obstacleGrid[i][j] == 1)return 0;
        if(i == n-1 && j == m-1)return 1;
        if(dp[i][j] != -1 )return dp[i][j];

        int right = 0;
        int down = 0;
        if(i+1 < n ) down =  path(n , m, i+1 , j , obstacleGrid,dp);

        if(j+1 < m) right =  path(n , m, i , j+1 , obstacleGrid,dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return path(n , m, 0 , 0 ,obstacleGrid ,dp);
    }
};