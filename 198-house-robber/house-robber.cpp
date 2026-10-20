class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1;i<n;i++){
            int left = prev1;
            int right = nums[i];
            if(i>1)right = prev2 + nums[i];

            int curr = max(left , right);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1; ;
    }
};