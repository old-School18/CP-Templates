// Time Complexity: O(V+E)
// Memory Complexity: O(V)
/*
 * Tarjan's Algorithm for Articulation Points (Cut Vertices) Detection
 * Articulation Points/cut-vertices: Vertices whose removal increases
 * the number of connected components in a graph
 */
// Undirected Graphs

void dfs(vector<vector<ll>> &adj, vector<ll> &discovery, vector<ll> &low, vector<ll> &articulationPoints, ll u,
         ll parent, ll &timer)
{
    ll children = 0;
    bool isArticulationPoint = false;
    discovery[u] = low[u] = ++timer;

    for (auto &v : adj[u])
    {
        if (v == parent)
        {
            continue;
        }

        if (!discovery[v])
        {
            children++;
            dfs(adj, discovery, low, articulationPoints, v, u, timer);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= discovery[u])
            {
                isArticulationPoint = true;
            }
        }
        else
        {
            low[u] = min(low[u], discovery[v]);
        }
    }

    if (isArticulationPoint || (parent == -1 && children > 1))
    {
        articulationPoints.push_back(u);
    }
    return;
}
vector<ll> tarjanArticulationPoints(vector<vector<ll>> &adj, ll n)
{
    vector<ll> articulationPoints;
    vector<ll> discovery(n + 1, 0);
    vector<ll> low(n + 1, 0);
    ll timer = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!discovery[i])
        {
            dfs(adj, discovery, low, articulationPoints, i, -1, timer);
        }
    }
    return articulationPoints;
}
