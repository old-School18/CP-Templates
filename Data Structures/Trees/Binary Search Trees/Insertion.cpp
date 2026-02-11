// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(1) Iterative | O(h) Recursive
// Insert node into BST

// Recursive
BST *insertIntoBSTRecursive(BST *root, ll val)
{
    if (root == nullptr)
    {
        return new BST(val);
    }

    if (root->data < val)
    {
        root->right = insertIntoBSTRecursive(root->right, val);
    }
    else
    {
        root->left = insertIntoBSTRecursive(root->left, val);
    }
	return root;
}

-----------------
// Iterative
BST *insertIntoBST(BST *root, ll val)
{
    BST *head = root;
    while (root)
    {
        if (root->data < val)
        {
            if (root->right)
            {
                root = root->right;
            }
            else
            {
                root->right = new BST(val);
                break;
            }
        }
        else
        {
            if (root->left)
            {
                root = root->left;
            }
            else
            {
                root->left = new BST(val);
                break;
            }
        }
    }
    if (head == nullptr)
    {
        head = new BST(val);
    }
    return head;
}
