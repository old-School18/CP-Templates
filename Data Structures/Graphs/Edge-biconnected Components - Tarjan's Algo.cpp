// Time Complexity: O(V+E)
// Memory Complexity: O(V)
/*
 * Edge-Biconnected Component: Removing any edge in a BCC does not disconnect the component. If you split a graph by
 * removing all its bridges, each component is a Edge-BCC.
 */
// Undirected Graphs

class PairHash
{
  public:
    size_t operator()(const pair<ll, ll> &p) const
    {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};

void dfs(vector<vector<ll>> &adj, vector<ll> &discovery, vector<ll> &low,
         unordered_set<pair<ll, ll>, PairHash> &bridges, ll u, ll parent, ll &timer)
{
    discovery[u] = low[u] = ++timer;

    for (auto &v : adj[u])
    {
        if (v == parent)
        {
            continue;
        }

        if (!discovery[v])
        {
            dfs(adj, discovery, low, bridges, v, u, timer);
            low[u] = min(low[u], low[v]);
            if (low[v] > discovery[u])
            {
                bridges.insert({u, v});
                bridges.insert({v, u});
            }
        }
        else
        {
            low[u] = min(low[u], discovery[v]);
        }
    }
    return;
}
unordered_set<pair<ll, ll>, PairHash> tarjanBridges(vector<vector<ll>> &adj, ll n)
{
    unordered_set<pair<ll, ll>, PairHash> bridges;
    vector<ll> discovery(n + 1, 0);
    vector<ll> low(n + 1, 0);
    ll timer = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!discovery[i])
        {
            dfs(adj, discovery, low, bridges, i, -1, timer);
        }
    }
    return bridges;
}

void assignComponentDfs(vector<vector<ll>> &adj, unordered_set<pair<ll, ll>, PairHash> &bridges, vector<ll> &component,
                        ll u, ll componentId)
{
    component[u] = componentId;

    for (auto &v : adj[u])
    {
        if (component[v] == -1 && !bridges.count({u, v}))
        {
            assignComponentDfs(adj, bridges, component, v, componentId);
        }
    }
    return;
}
vector<vector<ll>> tarjanEdgeBcc(vector<vector<ll>> &adj, ll n)
{
    unordered_set<pair<ll, ll>, PairHash> bridges = tarjanBridges(adj, n);

    vector<ll> component(n + 1, -1);
    ll componentId = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (component[i] == -1)
        {
            assignComponentDfs(adj, bridges, component, i, componentId++);
        }
    }

    vector<vector<ll>> edgeBcc(componentId);

    for (ll i = 1; i <= n; i++)
    {
        edgeBcc[component[i]].push_back(i);
    }
    return edgeBcc;
}
