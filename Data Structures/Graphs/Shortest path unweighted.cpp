// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Shortest path from a given source node to all nodes in an unweighted graph

vector<ll> shortestPathUnweighted(vector<vector<ll>> &adj, ll n, ll src)
{
    vector<ll> dist(n + 1, -1);
    queue<ll> qe;
    qe.push(src);
    dist[src] = 0;

    while (!qe.empty())
    {
        ll u = qe.front();
        qe.pop();
        for (auto &v : adj[u])
        {
            if (dist[v] == -1)
            {
                qe.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }

    return dist;
}
