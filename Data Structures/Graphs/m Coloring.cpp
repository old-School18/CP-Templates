// Time Complexity: O(V.m^V)
// Memory Complexity: O(V)
// Partition graph nodes into m groups such that no two nodes in a group share an edge

bool isSafe(vector<vector<ll>> &adj, vector<ll> &color, ll u, ll c)
{
    for (auto &v : adj[u])
    {
        if (color[v] == c)
        {
            return false;
        }
    }
    return true;
}
bool mColoringDfsUtil(vector<vector<ll>> &adj, ll n, ll m, vector<ll> &color, ll u)
{
    if (u > n)
    {
        return true;
    }
    for (ll c = 1; c <= m; c++)
    {
        if (isSafe(adj, color, u, c))
        {
            color[u] = c;
            if (mColoringDfsUtil(adj, n, m, color, u + 1))
            {
                return true;
            }
            color[u] = 0;
        }
    }
    return false;
}

bool mColoring(vector<vector<ll>> &adj, ll n, ll m)
{
    vector<ll> color(n + 1, 0);
    return mColoringDfsUtil(adj, n, m, color, 1);
}
