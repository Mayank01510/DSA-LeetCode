class Solution {
public:

    int theif(vector<int>& nums , int i,vector<int>& dp){
        if(i < 0)return 0;

        if(dp[i] != -1)return dp[i];

        if(i == 0)return nums[0];

        int left = theif(nums , i-2,dp) + nums[i];

        int right = theif(nums , i - 1,dp) ;

        return dp[i] = max(left , right);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        return theif(nums , n-1,dp);
    }
};