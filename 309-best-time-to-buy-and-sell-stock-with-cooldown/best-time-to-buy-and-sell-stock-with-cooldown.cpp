class Solution {
public:

    int stock(vector<int>& prices ,int i ,int buy , int cooldown ,vector<vector<vector<int>>>dp ){
        if(i == prices.size())return 0;

        if(dp[i][buy][cooldown] != -1)return dp[i][buy][cooldown];

        int profit = 0;

        if(buy){
            if(cooldown){
                profit = stock(prices , i+1 , 1 , 0,dp);
            }
            else{
                int take = -prices[i] + stock(prices , i+1 , 0 , 0, dp);
                int nottake = stock(prices , i+1 , 1 , 0 ,dp);

                profit = max(take , nottake);
            }
        }
        else{
            int sell = prices[i] + stock(prices , i+1 , 1 , 1, dp);
            int notsell = stock(prices , i+1 , 0 , 0 , dp);

            profit = max(sell , notsell);
        }
        return dp[i][buy][cooldown] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2 ,vector<int>(2, 0));

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                if(buy){
                    int take = -prices[i] + dp[i+1][0];
                    int nottake = dp[i+1][1];
                    dp[i][buy] = max(take , nottake);
                }
                else{
                    int sell = prices[i] + dp[i+2][1];
                    int notsell = dp[i+1][0];

                    dp[i][buy] = max(sell , notsell);
                }
            }
        }
        
        return dp[0][1];
    }
};