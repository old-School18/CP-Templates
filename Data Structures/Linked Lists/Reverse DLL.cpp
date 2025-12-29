// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Reverse a double Linked List

// Recursive
DoubleNode *reverseDLLRecurse(DoubleNode *prevNode, DoubleNode *curr)
{
    if (curr == nullptr)
    {
        return prevNode;
    }

    DoubleNode *nextNode = curr->next;
    curr->prev = nextNode;
    curr->next = prevNode;
    return reverseDLLRecurse(curr, nextNode);
}

DoubleNode *reverseDLL(DoubleNode *head)
{
    return reverseDLLRecurse(nullptr, head);
}

-------------------------------

// Iterative
DoubleNode *reverseDLL(DoubleNode *head)
{
    DoubleNode *prevNode = nullptr;
    DoubleNode *curr = head;
    while (curr != nullptr)
    {
        DoubleNode *nextNode = curr->next;
        curr->prev = nextNode;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    return prevNode;
}
