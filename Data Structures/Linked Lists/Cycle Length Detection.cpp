// Time Complexity: O(n)
// Memory Complexity: O(1)
// Determine Linked list Cycle length

ll cycle_length(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            ll cycle_length = 1;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                cycle_length++;
            }

            return cycle_length;
        }
    }

    return 0;
}
