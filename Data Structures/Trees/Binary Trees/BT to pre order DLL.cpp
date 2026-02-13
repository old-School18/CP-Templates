// Time Complexity: O(n)
// Memory Complexity: O(1) Morris | O(h) otherwise where h = tree height
// Binary to pre order double Linked list

// Recursive
void preOrderDLLRecurse(BT *root, BT *&head, BT *&prev)
{
    if (!root)
    {
        return;
    }

    BT *leftChild = root->left;
    BT *rightChild = root->right;
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

    preOrderDLLRecurse(leftChild, head, prev);
    preOrderDLLRecurse(rightChild, head, prev);
}

BT *preOrderDLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    preOrderDLLRecurse(root, head, prev);
    return head;
}

BT *preOrderLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    preOrderLLRecurse(root, head, prev);
    return head;
}

-----------------
// Iterative
BT *preOrderDLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    stack<BT *> stk;

    if (root)
    {
        stk.push(root);
    }

    while (!stk.empty())
    {
        BT *curr = stk.top();
        stk.pop();

        BT *leftChild = curr->left;
        BT *rightChild = curr->right;

        if (head == nullptr)
        {
            head = curr;
        }
        else
        {
            prev->right = curr;
        }
        curr->left = prev;
        prev = curr;

        if (rightChild)
        {
            stk.push(rightChild);
        }
        if (leftChild)
        {
            stk.push(leftChild);
        }
    }

    return head;
}

------------------
// Iterative - Morris
BT *preOrderDLL(BT *root)
{
    BT *head = root;
    BT *predecessor = nullptr;
    while (root)
    {
        if (root->left != nullptr)
        {
            BT *prev = root->left;
            while (prev->right)
            {
                prev = prev->right;
            }

            prev->right = root->right;
            root->right = root->left;
        }
        root->left = predecessor;
        predecessor = root;
        root = root->right;
    }

    return head;
}
