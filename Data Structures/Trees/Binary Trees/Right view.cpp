// Time Complexity: O(n)
// Memory Complexity: O(w) where w = tree width
// Right view of a binary tree

vector<ll> rightSideView(TreeNode *root)
{
    vector<ll> rightBoundary;
    queue<TreeNode *> qe;
    ll levels = 0;
    if (root)
    {
        qe.push(root);
    }

    while (!qe.empty())
    {
        ll currLevel = qe.size();
        ll rightNode;
        while (currLevel--)
        {
            auto p = qe.front();
            qe.pop();

            rightNode = p->val;

            if (p->left)
            {
                qe.push(p->left);
            }
            if (p->right)
            {
                qe.push(p->right);
            }
        }
        rightBoundary.push_back(rightNode);
    }
    return rightBoundary;
}
