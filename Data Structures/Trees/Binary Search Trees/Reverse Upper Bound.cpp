// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(1) Iterative | O(h) Recursive
// Reverse Upper bound

// Recursive
BST *reverseUpperBoundRecursive(BST *root, ll target)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->data < target)
    {
        BST *largerRUB = reverseUpperBoundRecursive(root->right, target);
        return largerRUB ? largerRUB : root;
    }
    else
    {
        return reverseUpperBoundRecursive(root->left, target);
    }
}

-----------------
// Iterative
BST *reverseUpperBound(BST *root, ll target)
{
    BST *rub = nullptr;

    while (root)
    {
        if (root->data < target)
        {
            rub = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return rub;
}
