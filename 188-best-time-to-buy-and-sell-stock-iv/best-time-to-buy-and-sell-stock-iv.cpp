class Solution {
public:

    int stock(vector<int>& prices , int i ,int buy, int cap , vector<vector<vector<int>>>& dp){
        if(i == prices.size() || cap == 0)return 0;

        if(dp[i][buy][cap] != -1)return dp[i][buy][cap];

        int profit = 0;

        if(buy){
            int take = -prices[i] + stock(prices , i+1 , 0 , cap , dp);
            int nottake = stock(prices , i+1 , 1 , cap , dp);

            profit = max(take , nottake);
        }
        else{
            int sell = prices[i] + stock(prices , i+1 , 1 , cap-1 , dp);
            int notsell = stock(prices , i+1 , 0 , cap , dp);

            profit = max(sell , notsell);
        }
        return dp[i][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2 ,vector<int>(k+1,0)));

        for(int i = n-1 ;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                for(int cap = 1;cap<=k;cap++){
                    if(buy){
                        int take = -prices[i] + dp[i+1][0][cap];
                        int nottake = dp[i+1][1][cap];

                        dp[i][buy][cap] = max(take , nottake);
                    }
                    else{
                        int sell = prices[i] +dp[i+1][1][cap-1];
                        int notsell = dp[i+1][0][cap];

                        dp[i][buy][cap] = max(sell , notsell);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};