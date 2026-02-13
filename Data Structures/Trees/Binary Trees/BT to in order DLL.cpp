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
BT *inOrderDLL(BT *root)
{
    BT *head = nullptr, *prev = nullptr;
    stack<BT *> stk;

    while (root || !stk.empty())
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }

        root = stk.top();
        stk.pop();
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
        root = root->right;
    }
    return head;
}

------------------
// Iterative - Morris
BT *inOrderDLL(BT *root)
{
    BT *head = nullptr, *predecessor = nullptr;

    while (root)
    {
        if (root->left != nullptr)
        {
            BT *prev = root->left;
            while (prev->right && prev->right != root)
            {
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                prev->right = root;
                root = root->left;
            }
            else
            {
                if (head == nullptr)
                {
                    head = root;
                }
                else
                {
                    predecessor->right = root;
                }
                root->left = predecessor;
                predecessor = root;
                root = root->right;
            }
        }
        else
        {
            if (head == nullptr)
            {
                head = root;
            }
            else
            {
                predecessor->right = root;
            }
            root->left = predecessor;
            predecessor = root;
            root = root->right;
        }
    }
    return head;
}
