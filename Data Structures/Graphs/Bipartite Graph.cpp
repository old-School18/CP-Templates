// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Determine if nodes of a graph can be partitioned into two groups such that every edge in the group connects a node from one group to a node from the other

// BFS
bool isBipartiteUtil(vector<vector<ll>> &adj, vector<ll> &color, ll u)
{
    queue<ll> qe;
    qe.push(u);
    color[u] = 0;
    while (!qe.empty())
    {
        ll p = qe.front();
        qe.pop();
        for (auto &q : adj[p])
        {
            if (color[q] == -1)
            {
                qe.push(q);
                color[q] = color[p] ^ 1;
            }
            else if (color[q] == color[p])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<ll>> &adj,ll n)
{
    vector<ll> color(n + 1, -1);
    for (ll u = 1; u <= n; u++)
    {
        if (color[u] == -1 && !isBipartiteUtil(adj, color, u))
        {
            return false;
        }
    }

    return true;
}

----------------------
// DFS
bool isBipartiteUtil(vector<vector<ll>> &adj, vector<ll> &color, ll u, ll c)
{
    color[u] = c;
    for (auto &v : adj[u])
    {
        if (color[v] == -1 && !isBipartiteUtil(adj, color, v, c ^ 1))
        {
            return false;
        }
        else if (color[v] == color[u])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<ll>> &adj,ll n)
{
    vector<ll> color(n + 1, -1);
    for (ll u = 1; u <= n; u++)
    {
        if (color[u] == -1 && !isBipartiteUtil(adj, color, u, 0))
        {
            return false;
        }
    }

    return true;
}
