class Solution {
public:
    vector<int>dp;
    int solve(int n ){
        if(n<=1)return n;
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        dp.assign(n+1,-1);
        return solve(n );
    }
};