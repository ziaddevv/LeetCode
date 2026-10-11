
class Solution {
public:
    using ll = long long;
    const ll INF = LLONG_MAX / 4;

    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));

        using State = tuple<ll, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        vector<vector<pair<int, int>>> adj(n);

        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        dist[0][k] = 0;
        pq.push({0, 0, k}); // {distance, node, count}

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d != dist[u][count])
                continue;

            for (auto [v, w] : adj[u]) {
                int newCount;

                if (labels[u] == labels[v]) {
                    if (count <= 1)
                        continue;

                    newCount = count - 1;
                } else {
                    newCount = k;
                }

                ll newDist = d + w;

                if (newDist < dist[v][newCount]) {
                    dist[v][newCount] = newDist;
                    pq.push({newDist, v, newCount});
                }
            }
        }

        ll ans = INF;

        for (int i = 1; i <= k; i++) {
            ans = min(ans, dist[n - 1][i]);
        }

        return ans == INF ? -1 : static_cast<int>(ans);
    }
};
