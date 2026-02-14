// Time Complexity: O(n) 
// Memory Complexity: O(1) Morris inorder | O(h) otherwise where h = tree height
// Validate if a tree is BST

// Range validation
bool isValidBST(BST *root, ll low, ll high)
{
    if (!root)
    {
        return true;
    }
    if (root->data <= low || root->data >= high)
    {
        return false;
    }
    return isValidBST(root->left, low, root->data) && isValidBST(root->right, root->data, high);
}

bool isValidBST(BST *root)
{
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}


-----------------
// Inorder - Morris used here for memory optimization, use any
bool isValidBST(BST *root)
{
    bool isHead = true;
    ll inOrderPrev = 0;
    bool isValid = true;
    while (root)
    {
        if (root->left == nullptr)
        {
            if (!isHead && inOrderPrev >= root->data)
            {
                isValid = false;
            }
            isHead = false;
            inOrderPrev = root->data;
            root = root->right;
        }
        else
        {
            BST *prev = root->left;
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
                if (!isHead && inOrderPrev >= root->data)
                {
                    isValid = false;
                }
                isHead = false;
                inOrderPrev = root->data;
                root = root->right;
            }
        }
    }
    return isValid;
}
