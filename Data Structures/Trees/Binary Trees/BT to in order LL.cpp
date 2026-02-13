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
BT *inOrderLL(BT *root)
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
        root->left = nullptr;
        prev = root;
        root = root->right;
    }
    return head;
}

------------------
// Iterative - Morris (Just for consistency with Morris threading of remaining traversals)
BT *inOrderLL(BT *root)
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
                prev->right = nullptr;
                if (head == nullptr)
                {
                    head = root;
                }
                else
                {
                    predecessor->right = root;
                }
                root->left = nullptr;
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
            root->left = nullptr;
            predecessor = root;
            root = root->right;
        }
    }
    return head;
}

------------------------
// Iterative - Morris simplified
BT *inOrderLL(BT *root)
{
    BT *head = nullptr, *predecessor = nullptr;

    while (root)
    {
        if (root->left != nullptr)
        {
            BT *prev = root->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = root;
            BT *next = root->left;
            root->left = nullptr;
            root = next;
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
            predecessor = root;
            root = root->right;
        }
    }
    return head;
}
