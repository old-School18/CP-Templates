// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// BFS

void bfs(vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n + 1, false);
    queue<ll> qe;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            qe.push(i);
            vis[i] = true;
            while (!qe.empty())
            {
                ll u = qe.front();
                qe.pop();
                for (auto &v : adj[u])
                {
                    if (!vis[v])
                    {
                        qe.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
    return;
}
