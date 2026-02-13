// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = tree height
// Binary tree to post order double Linked list

// Recursive
void postOrderDLLRecurse(BT *root, BT *&head, BT *&prev)
{
    if (!root)
    {
        return;
    }

    postOrderDLLRecurse(root->left, head, prev);
    postOrderDLLRecurse(root->right, head, prev);
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
}

BT *postOrderDLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    postOrderDLLRecurse(root, head, prev);
    return head;
}

-----------------
// Iterative


------------------
// Iterative - Morris
