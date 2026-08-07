class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>>q ;
        q.push({sr,sc});
        int start = image[sr][sc];
        image[sr][sc] = color;

        if(start == color)return image ;

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
                image[dr][dc] == start ){
                    q.push({dr,dc});
                    image[dr][dc] = color;
                }
            }
        }
        return image;
    }
};