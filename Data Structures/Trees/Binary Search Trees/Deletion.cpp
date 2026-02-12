// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(1) Iterative | O(h) Recursive
// Delete a node in a binary search tree

// Recursive
BST *deleteNodeRecursive(BST *root, ll key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->val > key)
    {
        root->left = deleteNodeRecursive(root->left, key);
    }
    else if (root->val == key)
    {
        if (!root->left || !root->right)
        {
            BST *temp = root->left ? root->left : root->right;
            delete (root);
            return temp;
        }

        BST *leftLargest = root->left;
        BST *leftLargestParent = root;
        while (leftLargest->right)
        {
            leftLargestParent = leftLargest;
            leftLargest = leftLargest->right;
        }

        root->val = leftLargest->val;

        if (leftLargestParent == root)
        {
            leftLargestParent->left = leftLargest->left;
        }
        else
        {
            leftLargestParent->right = leftLargest->left;
        }
        delete leftLargest;
        return root;
    }
    else
    {
        root->right = deleteNodeRecursive(root->right, key);
    }

    return root;
}

-----------------
// Iterative
BST *deleteNode(BST *root, ll key)
{
    BST *head = root, *parent = nullptr;
    while (root)
    {
        if (root->val > key)
        {
            parent = root;
            root = root->left;
        }
        else if (root->val == key)
        {
            if (!root->left || !root->right)
            {
                BST *temp = root->left ? root->left : root->right;
                if (!parent)
                {
                    delete (root);
                    head = temp;
                    break;
                }
                else
                {
                    if (parent->left == root)
                    {
                        parent->left = temp;
                    }
                    else
                    {
                        parent->right = temp;
                    }
                }
                delete (root);
                break;
            }

            BST *leftLargest = root->left;
            BST *leftLargestParent = root;
            while (leftLargest->right)
            {
                leftLargestParent = leftLargest;
                leftLargest = leftLargest->right;
            }
            root->val = leftLargest->val;
            if (leftLargestParent == root)
            {
                leftLargestParent->left = leftLargest->left;
            }
            else
            {
                leftLargestParent->right = leftLargest->left;
            }
            delete leftLargest;
            break;
        }
        else
        {
            parent = root;
            root = root->right;
        }
    }
    return head;
}
