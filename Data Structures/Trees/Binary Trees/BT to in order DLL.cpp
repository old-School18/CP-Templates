// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = tree height
// Binary tree to in order double Linked list

// Recursive
void inOrderDLLRecurse(BT *root, BT *&head, BT *&prev)
{
    if (!root)
    {
        return;
    }

    BT *rightChild = root->right;
    inOrderDLLRecurse(root->left, head, prev);
    if (!head)
    {
        head = root;
    }
    else
    {
        prev->right = root;
    }

    root->left = prev;
    prev = root;
    inOrderDLLRecurse(rightChild, head, prev);
}

BT *inOrderDLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    inOrderDLLRecurse(root, head, prev);
    return head;
}

-----------------
// Iterative


------------------
// Iterative - Morris
