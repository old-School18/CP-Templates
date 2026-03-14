// Time Complexity: O(V+E)
// Memory Complexity: O(V)
/*
 * Biconnected Component (Vertex-biconnected component): Removing any vertex in a BCC does not disconnect the
 * component.If you split a graph by its articulation points, each component is a BCC.
 */
// Undirected Graphs
void dfs(vector<vector<ll>> &adj, vector<ll> &discovery, vector<ll> &low, stack<pair<ll, ll>> &stk,
         vector<vector<pair<ll, ll>>> &bcc, ll u, ll parent, ll &timer)
{
    discovery[u] = low[u] = ++timer;

    for (auto v : adj[u])
    {
        if (v == parent)
            continue;
        if (!discovery[v])
        {
            stk.push({u, v});
            dfs(adj, discovery, low, stk, bcc, v, u, timer);
            low[u] = min(low[u], low[v]);

            if (low[v] >= discovery[u])
            {
                vector<pair<ll, ll>> component;
                while (true)
                {
                    pair<ll, ll> edge = stk.top();
                    stk.pop();
                    component.push_back(edge);
                    if (edge.first == u && edge.second == v)
                        break;
                }
                bcc.push_back(component);
            }
        }
        else if (discovery[v] < discovery[u])
        {
            low[u] = min(low[u], discovery[v]);
            stk.push({u, v});
        }
    }
    return;
}
vector<vector<pair<ll, ll>>> tarjanBcc(vector<vector<ll>> &adj, ll n)
{
    vector<vector<pair<ll, ll>>> bcc;
    vector<ll> discovery(n + 1, 0);
    vector<ll> low(n + 1, 0);
    stack<pair<ll, ll>> stk;
    ll timer = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!discovery[i])
        {
            dfs(adj, discovery, low, stk, bcc, i, -1, timer);
        }
    }
    return bcc;
}
