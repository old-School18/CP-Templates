// Time Complexity: O(V+E)
// Memory Complexity: O(V)
/*
 * Bridge-tree/Edge-biconnected Component Tree: Remove all bridges from a graph, compress each resulting connected
 * component into a single node and connect these nodes using the bridges. The resulting graph is a tree called bridge
 * tree. In simple terms, break down a graph into Edge-biconnected components and compress each Edge-BCC into a node and
 * connect these nodes with the graph bridges as edges.
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
vector<vector<ll>> bridgeTrees(vector<vector<ll>> &adj, ll n)
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

    vector<vector<ll>> trees(componentId);

    for (auto &[u, v] : bridges)
    {
        trees[component[u]].push_back(component[v]);
    }
    return trees;
}
