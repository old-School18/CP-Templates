// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Strongly Connected Components: Every vertex is reachable from every other vertex in a SCC. This algorithm breaks down a directed graph into SCCs
// Directed Graphs

void dfs(vector<vector<ll>> &adj, vector<bool> &vis, stack<ll> &stk, ll u)
{
    vis[u] = true;

    for (auto &v : adj[u])
    {
        if (!vis[v])
        {
            dfs(adj, vis, stk, v);
        }
    }

    stk.push(u);
}

void buildSccDfs(vector<vector<ll>> &revAdj, vector<bool> &vis, vector<ll> &component, ll u)
{
    vis[u] = true;
    component.push_back(u);

    for (auto &v : revAdj[u])
    {
        if (!vis[v])
        {
            buildSccDfs(revAdj, vis, component, v);
        }
    }
    return;
}

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
vector<vector<ll>> kosarajuScc(vector<vector<ll>> &adj, ll n)
{
    vector<vector<ll>> scc;
    vector<bool> vis(n + 1, false);
    stack<ll> stk;

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, stk, i);
        }
    }

    vector<vector<ll>> revAdj = transposeGraph(adj, n);

    fill(vis.begin(), vis.end(), false);

    while (!stk.empty())
    {
        ll u = stk.top();
        stk.pop();

        if (!vis[u])
        {
            vector<ll> component;
            buildSccDfs(revAdj, vis, component, u);
            scc.push_back(component);
        }
    }
    return scc;
}
