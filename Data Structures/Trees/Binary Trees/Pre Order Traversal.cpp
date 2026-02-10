// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = height of the tree
// Pre order traversal of a binary tree

// Recursive
void preOrderRecurse(BT *root, vector<ll> &preOrderNodes)
{
    if (root)
    {
        preOrderNodes.push_back(root->data);
        preOrderRecurse(root->left);
        preOrderRecurse(root->right);
    }
    return;
}

vector<ll> preOrder(BT *root)
{
    vector<ll> preOrderNodes;
    preOrderRecurse(root, preOrderNodes);
    return preOrderNodes;
}

---------------------
// Iterative
vector<ll> preOrder(BT *root)
{
    vector<ll> preOrderNodes;
    stack<BT *> stk;

    if (root)
    {
        stk.push(root);
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();

        preOrderNodes.push_back(p->data);

        if (p->right)
        {
            stk.push(p->right);
        }
        if (p->left)
        {
            stk.push(p->left);
        }
    }
    
    return preOrderNodes;
}

-----------------------
Morris Pre order traversal

vector<ll> preorder(BT *root)
{
    vector<ll> preOrderNodes;
    while (root != nullptr)
    {
        if (root->left == nullptr)
        {
            preOrderNodes.push_back(root->data);
            root = root->right;
        }
        else
        {
            BT *prev = root->left;
            while (prev->right && prev->right != root)
            {
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                prev->right = root;
                preOrderNodes.push_back(root->data);
                root = root->left;
            }
            else
            {
                prev->right = nullptr;
                root = root->right;
            }
        }
    }
    return preOrderNodes;
}
