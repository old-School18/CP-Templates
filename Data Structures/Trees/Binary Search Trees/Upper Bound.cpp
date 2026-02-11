// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(1) Iterative | O(h) Recursive
// Upper bound

// Recursive
BST *upperBoundRecursive(BST *root, ll target)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->data > target)
    {
        BST *smallerUB = upperBoundRecursive(root->left, target);
        return smallerUB ? smallerUB : root;
    }
    else
    {
        return upperBoundRecursive(root->right, target);
    }
}

-----------------
// Iterative
BST *upperBound(BST *root, ll target)
{
    BST *ub = nullptr;

    while (root)
    {
        if (root->data > target)
        {
            ub = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ub;
}
