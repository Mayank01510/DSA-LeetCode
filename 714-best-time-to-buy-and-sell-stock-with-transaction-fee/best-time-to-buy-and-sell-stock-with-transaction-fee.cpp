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
        vector<vector<int>>dp( n ,vector<int>(2 ,-1));
        
        return stock(prices , fee ,0 , 1 ,dp);
    }
};