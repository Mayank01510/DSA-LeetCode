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

        int dp1 = 0; // 0
        int dp2 = 0; // 1

        for(int i = n-1;i>=0;i--){
            int curr1 = 0;
            int curr2 = 0;
            for(int buy = 0;buy < 2;buy++){
                int profit = 0;

                if(buy){

                    int take = -prices[i] + dp1;
                    int notake = dp2;

                    curr2 = max(take , notake);
                }
                else{

                    int sell = prices[i] + dp2;
                    int notsell = dp1;

                    curr1 = max(sell , notsell);
                }
            }
            dp1 = curr1;
            dp2 = curr2;
        }

        return dp2;
    }
};