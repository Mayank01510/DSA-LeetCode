class Solution {
public:

    int stock(vector<int>& prices, int fee , int i , int buy , vector<vector<int>>& dp){
        if(i == prices.size())return 0;

        if(dp[i][buy] != -1)return dp[i][buy];

        int profit = 0;
        if(buy){
            int take = -prices[i] + stock(prices , fee ,i+1 , 0,dp);
            int nottake = stock(prices , fee ,i+1 , 1 , dp);

            profit = max(take , nottake);
        }
        else{
            int sell = prices[i] - fee + stock(prices , fee ,i+1 , 1 , dp);
            int notsell = stock(prices , fee ,i+1 , 0 , dp);

            profit = max(sell , notsell);
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp( n+1 ,vector<int>(2 ,0));

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                if(buy){
                    int take = -prices[i] + dp[i+1][0];
                    int nottake = dp[i+1][1];

                    dp[i][buy] = max(take , nottake);
                }
                else{
                    int sell = prices[i] - fee + dp[i+1][1];
                    int notsell = dp[i+1][0];

                    dp[i][buy] = max(sell , notsell);
                }
            }
        }
        
        return dp[0][1];
    }
};