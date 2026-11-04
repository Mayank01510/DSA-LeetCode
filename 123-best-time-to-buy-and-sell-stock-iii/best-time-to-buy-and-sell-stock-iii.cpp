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
        vector<vector<int>>after(2, vector<int>(3, 0));
        vector<vector<int>>curr(2, vector<int>(3, 0));


        for(int i = n-1 ;i>= 0;i--){
            for(int buy = 0;buy<2;buy++){
                for(int cap = 1;cap<3;cap++){
                    if(buy){

                        int take = -prices[i] + after[0][cap];
                        int notake = after[1][cap];

                        curr[buy][cap] = max(take , notake);
                    }
                    else{

                        int sell = prices[i] + after[1][cap-1];
                        int notsell = after[0][cap];

                        curr[buy][cap] = max(sell , notsell);
                    }
                }
            }
            after = curr;
        }

        return after[1][2];
    }
};