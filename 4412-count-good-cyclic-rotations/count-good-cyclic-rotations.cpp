class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(2*n);
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0;i<n;i++){
            if(i < n/2)sum1 += nums[i];
            else sum2 += nums[i];
            arr[i] = nums[i];
            arr[n+i] = nums[i];
        }
        int good = 0;
        int l = 0;
        int r = r;
        for(int i = 0;i<n;i++){
            if(sum1 > sum2 )good++;
            int mid = l + n/2 ;
            sum1 -= arr[i];
            sum1 += arr[mid];
            sum2 -= arr[mid];
            sum2 += arr[r];
            l++;
            r++;
        }
        return good;
    }
};