// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = height of the tree
// Post order traversal of a binary tree

// Recursive
void postOrderRecurse(BT *root, vector<ll> &postOrderNodes)
{
    if (root)
    {
        postOrderNodes.push_back(root->data);
        postOrderRecurse(root->right);
        postOrderRecurse(root->left);
    }
    return;
}

vector<ll> postOrder(BT *root)
{
    vector<ll> postOrderNodes;
    postOrderRecurse(root, postOrderNodes);
    reverse(postOrderNodes.begin(), postOrderNodes.end());
    return postOrderNodes;
}

---------------------
// Iterative
vector<ll> postOrder(BT *root)
{
    vector<ll> postOrderNodes;
    stack<BT *> stk;

    if (root)
    {
        stk.push(root);
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();

        postOrderNodes.push_back(p->data);

        if (p->left)
        {
            stk.push(p->left);
        }
        if (p->right)
        {
            stk.push(p->right);
        }
    }
    
    
    reverse(postOrderNodes.begin(), postOrderNodes.end());
    return postOrderNodes;
}

-----------------------
Morris Post order traversal

vector<ll> postOrder(BT *root)
{
    vector<ll> postOrderNodes;
    while (root != nullptr)
    {
        if (root->right == nullptr)
        {
            postOrderNodes.push_back(root->data);
            root = root->left;
        }
        else
        {
            BT *prev = root->right;
            while (prev->left && prev->left != root)
            {
                prev = prev->left;
            }

            if (prev->left == nullptr)
            {
                prev->left = root;
                postOrderNodes.push_back(root->data);
                root = root->right;
            }
            else
            {
                prev->left = nullptr;
                root = root->left;
            }
        }
    }
    reverse(postOrderNodes.begin(), postOrderNodes.end());
    return postOrderNodes;
}
