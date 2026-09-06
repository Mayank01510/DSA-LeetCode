class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        if(st.size() == nums.size())return false;
        return true;
    }
};