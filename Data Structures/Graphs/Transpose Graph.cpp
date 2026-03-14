// Time Complexity: O(V+E)
// Memory Complexity: O(1)
// Reverses all edges of a graph i.e., every u->v becomes v->u

vector<vector<ll>> transposeGraph(vector<vector<ll>> &adj, ll n)
{
    vector<vector<ll>> revAdj(n + 1);
    for (ll u = 1; u <= n; u++)
    {
        for (auto &v : adj[u])
        {
            revAdj[v].push_back(u);
        }
    }
    return revAdj;
}
