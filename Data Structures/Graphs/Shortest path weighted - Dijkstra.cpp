// Time Complexity: O((V+E)log V)
// Memory Complexity: O(V)
// Shortest path weighted graph. Doesn’t work with negative edges. Runs infinite loop for negative cycles


vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &adj, ll n, ll src)
{
    vector<ll> dist(n + 1, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;
        for (auto &[v, weight] : adj[u])
        {
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
