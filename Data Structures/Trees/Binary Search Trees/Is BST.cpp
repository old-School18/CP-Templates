// Time Complexity: O(n) 
// Memory Complexity: O(1) Morris inorder | O(h) otherwise where h = tree height
// Validate if a tree is BST

// Range validation
bool isValidBST(BT *root, ll low, ll high)
{
    if (!root)
    {
        return true;
    }
    if (root->val <= low || root->val >= high)
    {
        return false;
    }
    return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
}

bool isValidBST(BT *root)
{
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}


-----------------
// Inorder - Morris used here for memory optimization, use any
bool isValidBST(BT *root)
{
    bool isHead = true;
    ll inOrderPrev = 0;
    bool isValid = true;
    while (root)
    {
        if (root->left == nullptr)
        {
            if (!isHead && inOrderPrev >= root->val)
            {
                isValid = false;
            }
            isHead = false;
            inOrderPrev = root->val;
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
                if (!isHead && inOrderPrev >= root->val)
                {
                    isValid = false;
                }
                isHead = false;
                inOrderPrev = root->val;
                root = root->right;
            }
        }
    }
    return isValid;
}
