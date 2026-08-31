class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int i1 = 0;
        int i2 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                i1 = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                i2 = i;
            }
        }
        int left = max(i1,i2) + 1;
        int right = max(n-i1,n-i2);
        int ans = min(left , right);
        int s = min(i1,i2);
        int l = max(i1,i2);
        ans = min(ans , s+1 + n-l);
        return ans;
    }
};