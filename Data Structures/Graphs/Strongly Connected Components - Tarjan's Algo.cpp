// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Strongly Connected Components: Every vertex is reachable from every other vertex in a SCC. This algorithm breaks down a directed graph into SCCs
// Directed Graphs

void dfs(vector<vector<ll>> &adj, vector<ll> &discovery, vector<ll> &low, vector<bool> &inStack,
         stack<ll> &ancestralStack, vector<vector<ll>> &scc, ll u, ll &timer)
{
    discovery[u] = low[u] = ++timer;
    ancestralStack.push(u);
    inStack[u] = true;

    for (auto &v : adj[u])
    {
        if (!discovery[v])
        {
            dfs(adj, discovery, low, inStack, ancestralStack, scc, v, timer);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], discovery[v]);
        }
    }

    if (low[u] == discovery[u])
    {
        vector<ll> component;
        while (true)
        {
            ll v = ancestralStack.top();
            ancestralStack.pop();
            inStack[v] = false;
            component.push_back(v);
            if (v == u)
                break;
        }
        scc.push_back(component);
    }
    return;
}
vector<vector<ll>> tarjanScc(vector<vector<ll>> &adj, ll n)
{
    vector<vector<ll>> scc;
    vector<ll> discovery(n + 1, 0);
    vector<ll> low(n + 1, 0);
    vector<bool> inStack(n + 1, false);
    stack<ll> ancestralStack;
    ll timer = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!discovery[i])
        {
            dfs(adj, discovery, low, inStack, ancestralStack, scc, i, timer);
        }
    }
    return scc;
}
