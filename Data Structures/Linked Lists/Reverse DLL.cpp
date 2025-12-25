// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Reverse a double Linked List

// Recursive
DoubleNode *reverse_DLL_recurse(DoubleNode *prevNode, DoubleNode *curr)
{
    if (curr == nullptr)
    {
        return prevNode;
    }

    DoubleNode *nextNode = curr->next;
    curr->prev = nextNode;
    curr->next = prevNode;
    return reverse_DLL_recurse(curr, nextNode);
}

DoubleNode *reverse_DLL(DoubleNode *head)
{
    return reverse_DLL_recurse(nullptr, head);
}

-------------------------------

// Iterative
DoubleNode *reverse_DLL(DoubleNode *head)
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
