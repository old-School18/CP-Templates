// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(h) Recursive | O(1) Iterative
// Binary search in a BST

// Recursive
BST *binarySearch(BST *root, ll key)
{
    if (root == nullptr)
        return root;
    if (key < root->data)
        return binarySearch(root->left, key);
    else if (key > root->data)
        return binarySearch(root->right, key);

    return root;
}

// Iterative
BST *binarySearch(BST *root, ll key)
{
    while (root)
    {
        if (root->data > key)
        {
            root = root->left;
        }
        else if (root->data == key)
        {
            break;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}
