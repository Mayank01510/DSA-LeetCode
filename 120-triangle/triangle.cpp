class Solution {
public:

    int path(vector<vector<int>>& triangle , int n , int i , int j,vector<vector<int>>& dp){
        if(i == n-1)return triangle[i][j];

        if(dp[i][j] != -1)return dp[i][j];

        int a = path(triangle , n , i+1 , j,dp);
        int b = path(triangle , n , i+1 , j+1,dp);

        return dp[i][j] = triangle[i][j] + min(a,b);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<long long>>dp(n,vector<long long>(m,-1));

        for(int i = 0;i<triangle[0].size();i++)dp[0][i] = triangle[0][i];

        for(int i = 1;i<n;i++){
            for(int j = 0;j<triangle[i].size();j++){

                long a = INT_MAX;
                long b = INT_MAX;

                if(j < triangle[i-1].size()) a = triangle[i][j] + dp[i-1][j];
                if(j-1 >=0) b = triangle[i][j] + dp[i-1][j-1];

                dp[i][j] = min(a,b);

            }
        }

        long long minsum = INT_MAX;
        for(int i = 0;i<triangle[n-1].size();i++){
        minsum = min(minsum , dp[n-1][i]);
        }
        return minsum;
    }
};