// Time Complexity: O(logn)
// Memory Complexity: O(1) Iterative | O(h) Recursive where h = tree height
// Lower bound

// Recursive
BST *lowerBoundRecursive(BST *root, ll target)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->data >= target)
    {
        BST *smallerLB = lowerBound(root->left, target);
        return smallerLB ? smallerLB : root;
    }
    else
    {
        return lowerBound(root->right, target);
    }
}

-----------------
// Iterative
BST *lowerBound(BST *root, ll target)
{
    BST *lb = nullptr;

    while (root)
    {
        if (root->data >= target)
        {
            lb = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return lb;
}
