// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = tree height
// Binary tree to post order single Linked list

// Recursive
void postOrderLLRecurse(BT *root, BT *&head, BT *&prev)
{
    if (!root)
    {
        return;
    }

    postOrderLLRecurse(root->left, head, prev);
    postOrderLLRecurse(root->right, head, prev);
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
}

BT *postOrderLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    postOrderLLRecurse(root, head, prev);
    return head;
}

-----------------
// Iterative


------------------
// Iterative - Morris
