class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        // direction:
        // 0 = DOWN
        // 1 = RIGHT
        // 2 = UP
        // 3 = LEFT
        // 4 = no previous direction

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        // {cost, row, col, previousDirection, turns}
        priority_queue<
            tuple<int, int, int, int, int>,
            vector<tuple<int, int, int, int, int>>,
            greater<tuple<int, int, int, int, int>>
        > pq;

        // dist[row][col][direction][turns]
        vector<vector<vector<vector<int>>>> dist(
            n,
            vector<vector<vector<int>>>(
                m,
                vector<vector<int>>(5, vector<int>(k + 1, INT_MAX))
            )
        );

        // Starting cell
        dist[0][0][4][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0, 4, 0});

        while (!pq.empty()) {

            auto [cost, r, c, previousDirection, turns] = pq.top();
            pq.pop();

            // Ignore outdated state
            if (cost != dist[r][c][previousDirection][turns])
                continue;

            // We reached destination
            if (r == n - 1 && c == m - 1)
                return cost;

            for (int i = 0; i < 4; i++) {

                int row = r + drow[i];
                int col = c + dcol[i];

                // Boundary check
                if (row < 0 || row >= n ||
                    col < 0 || col >= m)
                    continue;

                // Current movement direction
                int newDirection = i;

                // Calculate new number of turns
                int newTurns = turns;

                // First move doesn't count as a turn
                if (previousDirection != 4 &&
                    previousDirection != newDirection) {

                    newTurns++;
                }

                // Cannot exceed k turns
                if (newTurns > k)
                    continue;

                int newCost = cost + grid[row][col];

                // If this state is better
                if (newCost <
                    dist[row][col][newDirection][newTurns]) {

                    dist[row][col][newDirection][newTurns] = newCost;

                    pq.push({
                        newCost,
                        row,
                        col,
                        newDirection,
                        newTurns
                    });
                }
            }
        }

        return -1;
    }
};