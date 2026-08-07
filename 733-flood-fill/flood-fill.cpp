class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color , int n ,int m , int start , int drow[] , int dcol[]){
        image[sr][sc] = color;

        for(int i = 0;i<4;i++){
                int dr = sr + drow[i];
                int dc = sc + dcol[i];
                if(dc >=0 && dr >=0 && dc < m && dr < n &&
                image[dr][dc] == start ){
                    dfs(image , dr , dc , color ,n,m,start , drow , dcol);
                }
            }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int start = image[sr][sc];

        if(start == color)return image ;

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        dfs(image , sr , sc , color ,n,m,start , drow , dcol);
        return image;
    }
};