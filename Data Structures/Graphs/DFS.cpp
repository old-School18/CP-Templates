// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// DFS

// Recursive
void dfsRecurse(vector<vector<ll>> &adj, vector<bool> &vis, ll u)
{
    vis[u] = true;

    for (auto &v : adj[u])
    {
        if (!vis[v])
        {
            dfsRecurse(adj, vis, v);
        }
    }
}

void dfs(vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n + 1, false);
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfsRecurse(adj, vis, i);
        }
    }
}

-------------------------
// Iterative
void dfs(vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n + 1, false);

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            stack<ll> stk;
            vis[i] = true;
            stk.push(i);

            while (!stk.empty())
            {
                ll u = stk.top();
                stk.pop();

                for (ll v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        stk.push(v);
                    }
                }
            }
        }
    }
}

