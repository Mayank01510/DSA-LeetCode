class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int s = flights.size();
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>> dis(n, vector<int>(k + 2, INT_MAX));  
        dis[src][0] = 0;
        for(int i = 0;i<s;i++){
            auto it = flights[i];
            int u = it[0];
            int v = it[1];
            int p = it[2];

            adj[u].push_back({v,p});
        }
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        pq.push({0 ,{0,src}});
        while(!pq.empty()){
            int price = pq.top().first;
            int stops = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if(node == dst )return price;
            if(stops == k+1)continue;

            for(auto it : adj[node]){
                int v = it.first;
                int m = it.second;
                int newstops = stops+1;
                if( price + m < dis[v][newstops]){
                    dis[v][newstops] = price + m;
                    pq.push({dis[v][newstops],{stops+1 , v}});
                }
            }
        }
        return -1;
    }
};