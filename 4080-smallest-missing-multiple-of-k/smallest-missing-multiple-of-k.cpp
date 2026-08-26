class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int i = 1;
        for( i = 1;i<=nums.size();i++){
            if(mpp.find(i*k) == mpp.end())return i*k;
        }
        return i*k;
    }
};