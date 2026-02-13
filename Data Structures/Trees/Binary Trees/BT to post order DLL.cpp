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
BT *reverseDLL(BT *head)
{
    BT *prevNode = nullptr;
    BT *curr = head;
    while (curr != nullptr)
    {
        BT *nextNode = curr->right;
        curr->left = nextNode;
        curr->right = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    return prevNode;
}

BT *postOrderDLL(BT *root)
{
    BT *head = nullptr, *predecessor = nullptr;
    stack<BT *> stk;

    if (root)
    {
        stk.push(root);
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();

        BT *leftChild = p->left;
        BT *rightChild = p->right;
        if (!head)
        {
            head = p;
        }
        else
        {
            predecessor->right = p;
        }
        p->left = predecessor;

        if (leftChild)
        {
            stk.push(leftChild);
        }
        if (rightChild)
        {
            stk.push(rightChild);
        }
    }

    return reverseDLL(head);
}

------------------
// Iterative - Morris
BT *flipDLLPointers(BT *head)
{
    BT *curr = head;
    BT *prev = nullptr;
    while (curr != nullptr)
    {
        prev = curr->left;
        if (prev)
        {
            prev->right = curr;
        }
        else
        {
            return curr;
        }
        curr = prev;
    }

    return prev;
}

BT *postOrderDLL(BT *root)
{
    BT *head = root;
    BT *predecessor = nullptr;
    while (root)
    {
        if (root->right != nullptr)
        {
            BT *prev = root->right;
            while (prev->left)
            {
                prev = prev->left;
            }

            prev->left = root->left;
            root->left = root->right;
        }
        root->right = predecessor;
        predecessor = root;
        root = root->left;
    }

    return flipDLLPointers(head);
}
