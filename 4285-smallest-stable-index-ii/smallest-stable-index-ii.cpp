class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long>mini(n);
        mini[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            mini[i] = min((long)nums[i] , mini[i+1]);
        }
        long long maxi = LONG_MIN;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > maxi) maxi = nums[i];
            int m = mini[i];
            if(maxi - m <= k)return i;
        }
        return -1;
    }
};