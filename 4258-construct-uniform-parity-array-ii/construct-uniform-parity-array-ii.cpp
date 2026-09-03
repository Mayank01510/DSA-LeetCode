class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = INT_MAX;
        int even = INT_MAX;
        for(int i = 0;i<n;i++){
            if(nums1[i] % 2 == 1)odd = min(odd,nums1[i]);
            else even = min(even,nums1[i]);
        }
        int e = 0;
        for(auto x : nums1){
            if(x%2 == 1){
                if(x <= odd)e = 1;
            }
        }
        if(e == 0)return true;

        int o = 0;
        for(auto x: nums1){
            if(x%2 == 0){
                if(x <= odd)o = 1;
            }
        }
        if(o == 0)return true;
        return false;
    }
};