// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Identify if a cycle exists in a linked list

// Recursive
bool isCycleDetectedRecurse(Node *slow, Node *fast)
{
    if (fast == nullptr || fast->next == nullptr)
    {
        return false;
    }

    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
        return true;
    }

    return isCycleDetectedRecurse(slow, fast);
}

bool isCycleDetected(Node *head)
{
    return isCycleDetectedRecurse(head, head);
}

-------------------------------

// Iterative
bool isCycleDetected(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
