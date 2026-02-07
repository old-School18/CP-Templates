// Time Complexity: O(nlogn)
// Memory Complexity: O(n)
// Bottom view of a binary tree - the last node in each column of vertical traversal of binary tree

vector<ll> bottomView(BT *root)
{
    vector<ll> bottomView;
    map<ll, ll> mp;
    queue<pair<BT *, ll>> qe;
    if (root)
    {
        qe.push({root, 0});
    }

    while (!qe.empty())
    {
        auto p = qe.front();
        qe.pop();

        mp[p.second] = p.first->data;

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
        bottomView.push_back(p.second);
    }

    return bottomView;
}
