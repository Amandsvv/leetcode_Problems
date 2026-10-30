class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build adjacency list: u -> {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[u][cnt] = minimum distance to reach node u with a consecutive label run of cnt
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        // Min-heap storing: {current_distance, node, consecutive_count}
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        // Start at node 0 with consecutive count = 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d > dist[u][cnt]) continue;
            if (u == n - 1) return d; // Reached target with minimal distance

            for (const auto& [v, wt] : adj[u]) {
                // Determine new consecutive streak
                int next_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (next_cnt <= k) {
                    if (d + wt < dist[v][next_cnt]) {
                        dist[v][next_cnt] = d + wt;
                        pq.push({dist[v][next_cnt], v, next_cnt});
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int c = 1; c <= k; ++c) {
            ans = min(ans, dist[n - 1][c]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};