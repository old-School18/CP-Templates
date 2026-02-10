// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = height of the tree
// In order traversal of a binary tree

// Recursive
void inOrderRecurse(BT *root, vector<ll> &inOrderNodes)
{
    if (root)
    {
        inOrderRecurse(root->left);
        inOrderRecurse.push_back(root->data);
        inOrderRecurse(root->right);
    }
    return;
}

vector<ll> inOrder(BT *root)
{
    vector<ll> inOrderNodes;
    inOrderRecurse(root, inOrderNodes);
    return inOrderNodes;
}

---------------------
// Iterative
vector<ll> inOrder(BT *root)
{
    vector<ll> inOrderNodes;
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
        inOrderNodes.push_back(curr->data);
        curr = curr->right;
    }

    return inOrderNodes;
}


-------------------------
Morris In order traversal

vector<ll> inOrder(BT *root)
{
    vector<ll> inorder;

    while (root != nullptr)
    {
        if (root->left == nullptr)
        {
            inorder.push_back(root->val);
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
                root = root->left;
            }
            else
            {
                prev->right = nullptr;
                inorder.push_back(root->val);
                root = root->right;
            }
        }
    }
    return inorder;
}
