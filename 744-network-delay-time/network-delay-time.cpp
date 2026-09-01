class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }
            priority_queue<
        pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dis(n+1,INT_MAX);
        dis[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto itt = pq.top();
            int wt = itt.first;
            int node = itt.second;
            pq.pop();

            for(auto it : adj[node]){
                int v = it.first;
                int weight = it.second;
                if(wt + weight < dis[v]){
                    dis[v] = wt + weight;
                    pq.push({dis[v] , v});
                }
            }
        }
        sort(dis.begin() , dis.end());
        if(dis[n-1] == INT_MAX)return -1;
        return dis[n-1];
    }
};