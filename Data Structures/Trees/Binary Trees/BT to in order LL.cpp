// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = tree height
// Binary tree to in order single Linked list

// Recursive
void inOrderLLRecurse(BT *root, BT *&head, BT *&prev)
{
    if (!root)
    {
        return;
    }

    BT *rightChild = root->right;
    inOrderLLRecurse(root->left, head, prev);
    if (!head)
    {
        head = root;
    }
    else
    {
        prev->right = root;
    }

    root->left = nullptr;
    prev = root;
    inOrderLLRecurse(rightChild, head, prev);
}

BT *inOrderLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    inOrderLLRecurse(root, head, prev);
    return head;
}

-----------------
// Iterative


------------------
// Iterative - Morris
