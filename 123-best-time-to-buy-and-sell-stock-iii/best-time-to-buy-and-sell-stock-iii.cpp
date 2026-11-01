class Solution {
public:

    int stock(vector<int>& prices , int n, int i , int buy ,int cap, vector<vector<vector<int>>>& dp){
        if(i == n || cap == 0)return 0;

        if(dp[i][buy][cap] != -1)return dp[i][buy][cap];

        int profit = 0;

        if(buy){

            int take = -prices[i] + stock(prices, n ,i+1, 0 , cap , dp);
            int notake = stock(prices, n ,i+1, 1,cap , dp);

            profit = max(take , notake);
        }
        else{

            int sell = prices[i] + stock(prices, n ,i+1, 1,cap-1 , dp);
            int notsell = stock(prices, n ,i+1, 0,cap,dp);

            profit = max(sell , notsell);
        }
        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return stock(prices , n, 0 , 1 , 2 ,dp);
    }
};