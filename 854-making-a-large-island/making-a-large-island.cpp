class disjointset{
    public:
        vector<int>size,parent;

        disjointset(int n){
            size.resize(n+1);
            parent.resize(n+1);

            for(int i = 0;i<n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findupar(int node){
            if(parent[node] == node)
                return node;

            return parent[node] = findupar(parent[node]);
        }

        void unionbysize(int u,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);

            if(ulp_u == ulp_v)return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointset ds(n*n);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 0)
                continue;

                int dr[] = {0,-1,0,1};
                int dc[] = {-1,0,1,0};

                for(int ind = 0;ind<4;ind++){
                    int r = i + dr[ind];
                    int c = j + dc[ind];

                    if(r>=0 && c>=0 && r<n && c < n && grid[r][c] == 1){
                        int node = i*n + j;
                        int adjnode = r*n + c;
                        ds.unionbysize(node , adjnode);
                    }
                }
            }
        }
        int mx = 0;

         for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1)
                continue;

                int dr[] = {0,-1,0,1};
                int dc[] = {-1,0,1,0};

                set<int>components;

                for(int ind = 0;ind<4;ind++){
                    int r = i + dr[ind];
                    int c = j + dc[ind];

                    if(r>=0 && c>=0 && r<n && c < n && grid[r][c] == 1){
                        int adjnode = r*n + c;
                        components.insert(ds.findupar(adjnode));
                    }
                }
                int sizetotal = 0;
                for(auto it : components){
                    sizetotal += ds.size[it];
                }
                mx = max(mx , sizetotal + 1);
            }
        }

        for(int i = 0;i < n*n ;i++){
            mx = max(mx , ds.size[ds.findupar(i)]);
        }

        return mx;
    }
};