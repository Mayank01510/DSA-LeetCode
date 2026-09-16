class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     if(s.length() == 0) return 0;
     int n = s.length();
       int maxi = 1;
       vector<int>hash(256,-1);
       int l = 0;
       int r = 0;
       while(n>r){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l) l = hash[s[r]]+1;
        }
        int length = r-l+1;
        maxi = max(maxi,length);
        hash[s[r]] = r;
        r++;
       }
       return maxi;
    }
};