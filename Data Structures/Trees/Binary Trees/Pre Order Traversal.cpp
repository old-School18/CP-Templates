// Time Complexity: O(n)
// Memory Complexity: O(h) where h = height of the tree
// Pre order traversal of a binary tree

// Recursive
void preOrderRecursive(BT *root)
{
    if (root)
    {
        cout << root->data << endl;
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
    return;
}

---------------------
// Iterative
void preOrder(BT *root)
{
    stack<BT *> stk;

    if (root)
    {
        stk.push(root);
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();

        cout << p->data << endl;

        if (p->right)
        {
            stk.push(p->right);
        }
        if (p->left)
        {
            stk.push(p->left);
        }
    }

    return;
}
