// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Reverse a single Linked List

// Recursive
Node *reverseLLRecurse(Node *prevNode, Node *curr)
{
    if (curr == nullptr)
    {
        return prevNode;
    }

    Node *nextNode = curr->next;
    curr->next = prevNode;
    return reverseLLRecurse(curr, nextNode);
}
Node *reverseLL(Node *head)
{
    return reverseLLRecurse(nullptr, head);
}


-------------------------------

// Recursive #2
Node *reverseLLRecursive(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *prevNode = reverseLLRecursive(head->next);

    Node *nextNode = head->next;
    nextNode->next = head;
    head->next = nullptr;

    return prevNode;
}

-------------------------------

// Iterative
Node *reverseLL(Node *head)
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
