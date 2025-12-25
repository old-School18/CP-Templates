// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Reverse a single Linked List

// Recursive
Node *reverse_LL_recurse(Node *prevNode, Node *curr)
{
    if (curr == nullptr)
    {
        return prevNode;
    }

    Node *nextNode = curr->next;
    curr->next = prevNode;
    return reverse_LL_recurse(curr, nextNode);
}
Node *reverse_LL(Node *head)
{
    return reverse_LL_recurse(nullptr, head);
}


-------------------------------

// Recursive #2
Node *reverse_LL_recursive(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *prevNode = reverse_LL_recursive(head->next);

    Node *nextNode = head->next;
    nextNode->next = head;
    head->next = nullptr;

    return prevNode;
}

-------------------------------

// Iterative
Node *reverse_LL(Node *head)
{
    Node *prevNode = nullptr;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    return prevNode;
}
