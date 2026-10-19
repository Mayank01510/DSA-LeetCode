class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[0] = nums[0];
        for(int i = 1;i<n;i++){
            int left = dp[i-1];
            int right = nums[i];
            if(i>1)right = dp[i-2] + nums[i];

            dp[i] = max(left , right);
        }

        return dp[n-1] ;
    }
};