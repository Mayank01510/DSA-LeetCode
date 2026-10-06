class disjointset{
    public:
        vector<int>size , rank , parent;
        disjointset(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findupar(int node){
            if(node == parent[node])
            return node;

            return parent[node] = findupar(parent[node]);
        }

        void unionbyrank(int u,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);
            if(ulp_u == ulp_v)return;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionbysize(int u ,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);
            if(ulp_u == ulp_v)return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int cntextras = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findupar(u) == ds.findupar(v)){
                cntextras++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int cntc = 0;
        for(int i = 0;i<n;i++){
            if(ds.parent[i] == i)cntc++;
        }
        
        int ans = cntc - 1;
        if(cntextras >= ans)return ans;
        return -1;
    }
};