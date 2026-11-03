class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int big = nums[n-1];
        int sum = 0;

        for(int i = 0;i<n;i++){
            sum += big - nums[i];
        }
        return sum;
    }
};