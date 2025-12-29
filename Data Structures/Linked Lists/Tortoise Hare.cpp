// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Identify the middle element of a linked list. For even sized lists, identify the latter middle element. If the requirement is to identify the former middle element in even sized lists, initialise fast as head->next

// Recursive
Node *tortoiseHareRecurse(Node *slow, Node *fast)
{
    if (fast == nullptr || fast->next == nullptr)
    {
        return slow;
    }

    return tortoiseHareRecurse(slow->next, fast->next->next);
}
Node *tortoiseHare(Node *head)
{
    return tortoiseHareRecurse(head, head);
}

-------------------------------

// Iterative
Node *tortoiseHare(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
