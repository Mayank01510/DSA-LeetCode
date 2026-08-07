class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        queue<pair<int,int>>q ;
        q.push({sr,sc});
        visit[sr][sc] = 1;
        int start = image[sr][sc];

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int dr = r + drow[i];
                int dc = c + dcol[i];
                if(dc >=0 && dr >=0 && dc < m && dr < n &&
                image[dr][dc] == start && !visit[dr][dc]){
                    q.push({dr,dc});
                    image[dr][dc] = color;
                    visit[dr][dc] = 1;
                }
            }
        }
        image[sr][sc] = color;

        return image;
    }
};