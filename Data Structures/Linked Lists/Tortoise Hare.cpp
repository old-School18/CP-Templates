// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Identify the middle element of a linked list. For even sized lists, identify the latter middle element.

// Recursive
Node *tortoise_hare_recurse(Node *slow, Node *fast)
{
    if (fast == nullptr || fast->next == nullptr)
    {
        return slow;
    }

    return tortoise_hare_recurse(slow->next, fast->next->next);
}
Node *tortoise_hare(Node *head)
{
    return tortoise_hare_recurse(head, head);
}

-------------------------------

// Iterative
Node *tortoise_hare(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
