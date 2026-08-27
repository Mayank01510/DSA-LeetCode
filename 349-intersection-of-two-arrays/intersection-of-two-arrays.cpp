class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp1;
        for(int i = 0;i<nums1.size();i++){
            mpp1[nums1[i]]++;
        }

        unordered_map<int,int>mpp2;
        for(int i = 0;i<nums2.size();i++){
            mpp2[nums2[i]]++;
        }

        set<int>st;
        for(int i = 0;i<nums1.size();i++){
            if(mpp1.find(nums1[i]) != mpp1.end() && mpp2.find(nums1[i]) != mpp2.end())st.insert(nums1[i]);
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};