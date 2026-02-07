// Time Complexity: O(nlogn)
// Memory Complexity: O(n)
// Top view of a binary tree - the first node in each column of vertical traversal of binary tree

vector<ll> topView(BT *root)
{
    vector<ll> topViewNodes;
    unordered_map<ll, ll> mp;
    queue<pair<BT *, ll>> qe;
    if (root)
    {
        qe.push({root, 0});
    }

    while (!qe.empty())
    {
        auto p = qe.front();
        qe.pop();

        if (mp.find(p.second) == mp.end())
        {
            mp[p.second] = p.first->data;
        }

        if (p->left)
        {
            qe.push({p->left, p.second - 1});
        }
        if (p->right)
        {
            qe.push({p->right, p.second + 1});
        }
    }

    for (auto &p : mp)
    {
        topViewNodes.push_back(p.second);
    }

    return topViewNodes;
}
