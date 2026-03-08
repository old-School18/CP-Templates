// Time Complexity: O(V*E)
// Memory Complexity: O(V)
// Shortest path weighted graph. Works with negative edges. Detects negative cycles

vector<ll> bellmanFord(vector<vector<ll>> &edges, ll n, ll src)
{
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[src] = 0;
    for (ll i = 1; i < n; i++)
    {
    	bool changed=false;
        for (auto &e : edges)
        {
            ll u = e[0], v = e[1], w = e[2];
            if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                changed=true;
            }
        }
        
        if(!changed) break;
    }

    for (auto &e : edges)
    {
        ll u = e[0], v = e[1], w = e[2];
        if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w)
        {
            return {}; // negative cycle
        }
    }

    return dist;
}
