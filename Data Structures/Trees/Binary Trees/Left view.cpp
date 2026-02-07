// Time Complexity: O(n)
// Memory Complexity: O(w) where w = tree width
// Left view of a binary tree

vector<ll> leftSideView(TreeNode *root)
{
    vector<ll> leftBoundary;
    queue<TreeNode *> qe;
    ll levels = 0;
    if (root)
    {
        qe.push(root);
    }

    while (!qe.empty())
    {
        ll currLevel = qe.size();
        ll leftNode;
        while (currLevel--)
        {
            auto p = qe.front();
            qe.pop();

            leftNode = p->val;

            if (p->right)
            {
                qe.push(p->right);
            }
            if (p->left)
            {
                qe.push(p->left);
            }
        }
        leftBoundary.push_back(leftNode);
    }
    return leftBoundary;
}
