class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(int i = 0;i<n;i++){
            dis[i][i] = 0;
        }
        
        for(int i = 0;i<edges.size();i++){
            auto it = edges[i];
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dis[u][v] = w;
            dis[v][u] = w;
        }
        for(int k = 0 ;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX)
                    dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
                }
            }
        }
        
        int mincount = INT_MAX;
        int city = -1;
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                if( i != j && dis[i][j] <= distanceThreshold)count++;
            }
            if(count <= mincount){
                mincount = count;
                city = i;
            }
        }
        return city;
    }
};