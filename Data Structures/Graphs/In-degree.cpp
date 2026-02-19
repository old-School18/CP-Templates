// Time Complexity: O(V+E)
// Memory Complexity: O(1)
// Indegree

vector<ll> getIndegree(vector<vector<ll>> &adj, ll n)
{
    vector<ll> indegree(n + 1);
    for (ll u = 1; u <= n; u++)
    {
        for (auto &v : adj[u])
        {
            indegree[v]++;
        }
    }

    return indegree;
}
