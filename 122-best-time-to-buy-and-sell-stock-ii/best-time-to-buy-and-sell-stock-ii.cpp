class Solution {
public:

    int stock(vector<int>& prices , int n, int i , int buy , vector<vector<int>>& dp){
        if(i == n)return 0;

        if(dp[i][buy] != 1e8)return dp[i][buy];

        int profit = 0;

        if(buy){

            int take = -prices[i] + stock(prices, n ,i+1, 0 ,dp);
            int notake = stock(prices, n ,i+1, 1,dp);

            profit = max(take , notake);
        }
        else{

            int sell = prices[i] + stock(prices, n ,i+1, 1,dp);
            int notsell = stock(prices, n ,i+1, 0,dp);

            profit = max(sell , notsell);
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1 , vector<int>(2,0));

        dp[n][0] = dp[n][1] = 0;

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy < 2;buy++){
                int profit = 0;

                if(buy){

                    int take = -prices[i] + dp[i+1][0];
                    int notake = dp[i+1][1];

                    profit = max(take , notake);
                }
                else{

                    int sell = prices[i] + dp[i+1][1];
                    int notsell = dp[i+1][0];

                    profit = max(sell , notsell);
                }
                dp[i][buy] = profit;
            }

        }

        return dp[0][1];
    }
};