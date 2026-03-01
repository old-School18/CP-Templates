// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Order the vertices in a DAG such that node u occurs before v in the ordering if there is a directed edge from u to v

// BFS - Kahn's Algorithm
vector<ll> getIndegree(vector<vector<ll>> &adj, ll n)
{
    vector<ll> indegree(n + 1, 0);
    for (ll u = 1; u <= n; u++)
    {
        for (auto &v : adj[u])
        {
            indegree[v]++;
        }
    }

    return indegree;
}

vector<ll> topoSort(vector<vector<ll>> &adj, ll n)
{
    vector<ll> topoSortedNodes;
    vector<ll> indegree = getIndegree(adj, n);
    queue<ll> qe;
    ll visited = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (!indegree[i])
        {
            qe.push(i);
        }
    }

    while (!qe.empty())
    {
        ll u = qe.front();
        qe.pop();

        topoSortedNodes.push_back(u);
        visited++;
        for (auto &v : adj[u])
        {
            indegree[v]--;
            if (!indegree[v])
            {
                qe.push(v);
            }
        }
    }

    if (visited != n)
        return {}; // cycle detected
    return topoSortedNodes;
}


----------------------------
// DFS
bool topoSortDfsUtil(vector<vector<ll>> &adj, vector<ll> &state, vector<ll> &topoSortedNodes, ll u)
{
    state[u] = 1; // visiting

    for (auto &v : adj[u])
    {
        if (!state[v] && topoSortDfsUtil(adj, state, topoSortedNodes, v))
        {
            return true; // cycle detected
        }
        else if (state[v] == 1)
        {
            return true; // cycle detected
        }
    }

    state[u] = 2; // visited
    topoSortedNodes.push_back(u);
    return false;
}

vector<ll> topoSort(vector<vector<ll>> &adj, ll n)
{
    vector<ll> topoSortedNodes;
    vector<ll> state(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        if (!state[i] && topoSortDfsUtil(adj, state, topoSortedNodes, i))
        {
            return {}; // cycle detectd
        }
    }

    reverse(topoSortedNodes.begin(), topoSortedNodes.end());
    return topoSortedNodes;
}
