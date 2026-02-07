// Time Complexity: O(n)
// Memory Complexity: O(n) Worst case | O(h) Average case where h = height of the tree
// Pre Order, In Order, Post Order traversals in one traversal

vector<vector<ll>> preInPostTraversal(BT *root)
{
    vector<ll> preOrder, inOrder, postOrder;
    stack<pair<BT *, ll>> stk;
    if (root)
    {
        stk.push({root, 1});
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();

        if (p.second == 1)
        {
            preOrder.push_back(p.first->data);

            stk.push({p.first, 2});

            if (p.first->left)
            {
                stk.push({p.first->left, 1});
            }
        }
        else if (p.second == 2)
        {
            inOrder.push_back(p.first->data);
            stk.push({p.first, 3});

            if (p.first->right)
            {
                stk.push({p.first->right, 1});
            }
        }
        else
        {
            postOrder.push_back(p.first->data);
        }
    }

    return {preOrder, inOrder, postOrder};
}
