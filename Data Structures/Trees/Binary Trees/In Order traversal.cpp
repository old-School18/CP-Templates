// Time Complexity: O(n)
// Memory Complexity: O(h) where h = height of the tree
// In order traversal of a binary tree

// Recursive
void inorderRecurse(BT *root, vector<ll> &inOrderNodes)
{
    if (root)
    {
        inorderRecurse(root->left);
        inOrderNodes.push_back(root->data);
        inorderRecurse(root->right);
    }
    return;
}

vector<ll> inorder(BT *root)
{
    vector<ll> inOrderNodes;
    inorderRecurse(root, inOrderNodes);
    return inOrderNodes;
}

---------------------
// Iterative
vector<ll> inorder(BT *root)
{
    vector<ll> inorderNodes;
    stack<BT *> stk;
    BT *curr = root;

    while (curr != nullptr || !stk.empty())
    {
        while (curr != nullptr)
        {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();
        inorderNodes.push_back(curr->data);
        curr = curr->right;
    }

    return inorderNodes;
}
