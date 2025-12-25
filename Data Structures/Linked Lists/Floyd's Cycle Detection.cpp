// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Identify if a cycle exists in a linked list

// Recursive
bool is_cycle_detected_recurse(Node *slow, Node *fast)
{
    if (fast == nullptr || fast->next == nullptr)
    {
        return false;
    }

    if (slow == fast)
    {
        return true;
    }

    return is_cycle_detected_recurse(slow->next, fast->next->next);
}

bool is_cycle_detected(Node *head)
{
    return is_cycle_detected_recurse(head, head);
}

-------------------------------

// Iterative
bool is_cycle_detected(Node *head)
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
