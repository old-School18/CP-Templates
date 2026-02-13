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
BT *reverseLL(BT *head)
{
    BT *prevNode = nullptr;
    BT *curr = head;
    while (curr != nullptr)
    {
        BT *nextNode = curr->right;
        curr->right = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    return prevNode;
}

BT *postOrderLL(BT *root)
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
        p->left = nullptr;

        if (leftChild)
        {
            stk.push(leftChild);
        }
        if (rightChild)
        {
            stk.push(rightChild);
        }
    }

    return reverseLL(head);
}

------------------
// Iterative - Morris
BT *flipLLPointers(BT *head)
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
        curr->left = nullptr;
        curr = prev;
    }
    return prev;
}

BT *postOrderLL(BT *root)
{
    BT *head = root;
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
            root->right = nullptr;
        }
        root = root->left;
    }

    return flipLLPointers(head);
}
