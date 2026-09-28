class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int m = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '(')count++;
            else if(s[i] == ')')count--;
            m = max(m,count);
        }
        return m;
    }
};