class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = 0;
        int n = haystack.size();
        int r = 0;
        while(r<n){
            int p = r;
            while( l<needle.size() && haystack[r] == needle[l] ){
                l++;
                r++;
            }
            if(l == needle.size())return p;
            else l = 0 , r = p;
            r++;
        }
        return -1;
    }
};