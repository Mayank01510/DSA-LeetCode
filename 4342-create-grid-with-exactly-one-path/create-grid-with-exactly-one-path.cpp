class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;

        string p(n,'.');
        ans.push_back(p);
        for(int i = 1;i<m;i++){
            string s(n,' ');
            for(int j = 0;j<n;j++){
                if(j == n-1)s[j] = '.';
                else s[j] = '#';
            }
            ans.push_back(s);
        }
            return ans;
    }
};