// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Zig zag traversal of tree - traverse left to right at odd levels and right to left at even levels

vector<vector<ll>> zigzagLevelOrder(BT *root)
{
    vector<vector<ll>> zigzag;
    queue<BT *> qe;
    if (root)
    {
        qe.push(root);
    }

    ll levels = 0;
    while (!qe.empty())
    {
        ll currLevelSize = qe.size();
        vector<ll> currLevel(currLevelSize);
        levels++;

        ll idx = (levels % 2 ? 0 : currLevelSize - 1);
        while (currLevelSize--)
        {
            auto p = qe.front();
            qe.pop();
            if (p->left)
            {
                qe.push(p->left);
            }
            if (p->right)
            {
                qe.push(p->right);
            }

            currLevel[idx] = p->data;
            idx += (levels % 2 ? 1 : -1);
        }
        zigzag.push_back(currLevel);
    }

    return zigzag;
}
