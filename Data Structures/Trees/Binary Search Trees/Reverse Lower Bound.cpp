// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(1) Iterative | O(h) Recursive
// Reverse Lower bound

// Recursive
BST *reverseLowerBoundRecursive(BST *root, ll target)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->data <= target)
    {
        BST *largerRLB = reverseLowerBoundRecursive(root->right, target);
        return largerRLB ? largerRLB : root;
    }
    else
    {
        return reverseLowerBoundRecursive(root->left, target);
    }
}

-----------------
// Iterative
BST *reverseLowerBound(BST *root, ll target)
{
    BST *rlb = nullptr;

    while (root)
    {
        if (root->data <= target)
        {
            rlb = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return rlb;
}
