class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = 0;
        pq.push({0,{0,0}});

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!pq.empty()){
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return d;

            for(int i = 0;i<4;i++){
                int r = row + drow[i];
                int c = col + dcol[i];
                if(r<n && r>=0 && c<m && c>=0 ){
                    int diff = abs(heights[row][col] - heights[r][c]) ;
                    int effort = max(diff,d);
                    if(effort < dis[r][c]){
                        dis[r][c] = effort;
                        pq.push({dis[r][c],{r,c}});
                    }
                }
            }
        }
        return 0;
    }
};