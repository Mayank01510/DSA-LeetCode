class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int>>> adj(n);

        // Build adjacency list
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int city = -1;
        int minCount = INT_MAX;

        // Run Dijkstra from every city
        for(int src = 0; src < n; src++) {

            vector<long long> dist(n, LLONG_MAX);

            priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > pq;

            dist[src] = 0;
            pq.push({0, src});

            while(!pq.empty()) {

                auto [d, node] = pq.top();
                pq.pop();

                // Ignore outdated entry
                if(d > dist[node])
                    continue;

                for(auto [next, wt] : adj[node]) {

                    if(d + wt < dist[next] &&
                       d + wt <= distanceThreshold) {

                        dist[next] = d + wt;
                        pq.push({dist[next], next});
                    }
                }
            }

            // Count reachable cities
            int count = 0;

            for(int i = 0; i < n; i++) {
                if(i != src && dist[i] <= distanceThreshold) {
                    count++;
                }
            }

            // Smaller count is better
            // If equal, larger city number is better
            if(count <= minCount) {
                minCount = count;
                city = src;
            }
        }

        return city;
    }
};