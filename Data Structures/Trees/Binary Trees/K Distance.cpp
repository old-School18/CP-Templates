// Time Complexity: O(n)
// Memory Complexity: O(h) DFS | O(n) BFS where h = tree height
// All nodes that are at a distance k from a given node

// DFS
void collectFromSubTree(BT *root, ll k, ll depth, vector<ll> &kNodes)
{
    if (root == nullptr || depth > k)
    {
        return;
    }
    if (depth == k)
    {
        kNodes.push_back(root->data);
        return;
    }
    collectFromSubTree(root->left, k, depth + 1, kNodes);
    collectFromSubTree(root->right, k, depth + 1, kNodes);
    return;
}

ll dfs(BT *root, BT *target, ll k, vector<ll> &kNodes)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root == target)
    {
        collectFromSubTree(root, k, 0, kNodes);
        return 1;
    }

    ll left = dfs(root->left, target, k, kNodes);
	if (left != -1)
    {
        if (left == k)
            kNodes.push_back(root->data);
        else
            collectFromSubTree(root->right, k, left + 1, kNodes);
        return left + 1;
    }
	
    ll right = dfs(root->right, target, k, kNodes);
    if (right != -1)
    {
        if (right == k)
            kNodes.push_back(root->data);
        else
            collectFromSubTree(root->left, k, right + 1, kNodes);
        return right + 1;
    }
	
    return -1;
}

vector<ll> kDistance(BT *root, BT *target, ll k)
{
    vector<ll> kNodes;
    dfs(root, target, k, kNodes);
    return kNodes;
}

-------------------
// BFS - with back-edges
vector<ll> kDistance(BT *root, BT *target, ll k)
{
    if (!root || !target)
        return {};

    unordered_map<BT *, BT *> parentMap;
    unordered_set<BT *> visited;
    queue<BT *> qe;

    qe.push(root);
    while (!qe.empty())
    {
        auto p = qe.front();
        qe.pop();

        if (p->left)
        {
            parentMap[p->left] = p;
            qe.push(p->left);
        }
        if (p->right)
        {
            parentMap[p->right] = p;
            qe.push(p->right);
        }
    }

    ll level = 0;
    qe.push(target);
    visited.insert(target);

    while (!qe.empty())
    {
        ll currLeveLSize = qe.size();
        if (level++ == k)
        {
            vector<ll> res;
            while (!qe.empty())
            {
                res.push_back(qe.front()->val);
                qe.pop();
            }
            return res;
        }

        while (currLeveLSize--)
        {
            auto p = qe.front();
            qe.pop();

            if (parentMap.count(p) && !visited.count(parentMap[p]))
            {
                visited.insert(parentMap[p]);
                qe.push(parentMap[p]);
            }
            if (p->left && !visited.count(p->left))
            {
                visited.insert(p->left);
                qe.push(p->left);
            }
            if (p->right && !visited.count(p->right))
            {
                visited.insert(p->right);
                qe.push(p->right);
            }
        }
    }
    return {};
}
