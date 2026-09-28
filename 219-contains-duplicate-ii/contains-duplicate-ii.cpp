class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto it : mpp){
            vector<int>v = it.second;
            if(v.size()>1){
                for(int j = 1;j<v.size();j++)
                if(v[j] - v[j-1] <= k)return true;
            }
        }
        return false;
    }
};