// Time Complexity: O(V+E) Predecessor algo | O(V!) state space algo
// Memory Complexity: O(V+E) Predecessor algo | O(V!) state space algo
// BFS determines shortest path while DFS traverses all paths. This is BFS to traverse all shortest paths

// Predecessor tracker BFS
void bfsPredecessors(vector<vector<ll>> &adj, ll n)
{
    vector<vector<ll>> ancestors(n+1);
    vector<ll> dist(n + 1, -1);
    queue<ll> qe;
    for (ll i = 1; i <= n; i++)
    {
        if (dist[i] == -1)
        {
            qe.push(i);
			dist[i]=0;
            while (!qe.empty())
            {
                ll u = qe.front();
                qe.pop();
                for (auto &v : adj[u])
                {
                    if (dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        ancestors[v].push_back(u);
                        qe.push(v);
                    }
                    else if (dist[v] == dist[u] + 1)
                    {
                        ancestors[v].push_back(u);
                    }
                }
            }
        }
    }
    return;
}

---------------------

// State space BFS
void bfsStateSpace(vector<vector<ll>> &adj, ll n)
{
    vector<ll> vis(n + 1, 0);
    queue<vector<ll>> qe;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            qe.push({i});
            ll level = 1;
            vis[i] = level;
            while (!qe.empty())
            {
                ll currLevelSize = qe.size();
                level++;
                while (currLevelSize--)
                {
                    vector<ll> path = qe.front();
                    qe.pop();
                    for (auto &v : adj[path.back()])
                    {
                        if (!vis[v] || vis[v] == level)
                        {
                            vis[v] = level;
                            path.push_back(v);
                            qe.push(path);
                            path.pop_back();
                        }
                    }
                }
            }
        }
    }
    return;
}


----------------------
Reference:
https://leetcode.com/problems/word-ladder-ii/
