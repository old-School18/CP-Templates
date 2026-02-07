// Time Complexity: O(nlogn)
// Memory Complexity: O(n)
// Vertical traversal of a binary tree

vector<vector<ll>> verticalTraversal(BT *root)
{
    map<ll, map<ll, multiset<ll>>> nodes;
    queue<pair<BT *, pair<ll, ll>>> qe; // node, (col, row)

    if (root)
        qe.push({root, {0, 0}});

    while (!qe.empty())
    {
        auto [node, pos] = qe.front();
        qe.pop();

        ll col = pos.first;
        ll row = pos.second;

        nodes[col][row].insert(node->val);

        if (node->left)
            qe.push({node->left, {col - 1, row + 1}});
        if (node->right)
            qe.push({node->right, {col + 1, row + 1}});
    }

    vector<vector<ll>> result;
    for (auto &[col, rows] : nodes)
    {
        vector<ll> curr;
        for (auto &[row, vals] : rows)
            curr.insert(curr.end(), vals.begin(), vals.end());

        result.push_back(curr);
    }

    return result;
}

--------------------
Reference:
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
