class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));

        dis[0][0] = 0;
        pq.push({0,{0,0}});

        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};

        while(!pq.empty()){
            int t = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1)return t;

            for(int i = 0;i<4;i++){
                int r = row + drow[i];
                int c = col + dcol[i];

                if(r < n && c<n && c>=0 && r >=0 ){
                    int diff = max(grid[r][c] , grid[row][col]);
                    int time = max(diff,t);
                    if(dis[r][c] > time){
                        dis[r][c] = time;
                        pq.push({time,{r,c}});
                    }
                }
            }
        }
        return 0;
    }
};