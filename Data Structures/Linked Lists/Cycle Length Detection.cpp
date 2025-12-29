// Time Complexity: O(n)
// Memory Complexity: O(1)
// Determine Linked list Cycle length

ll cycleLength(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            ll cycleLength = 1;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                cycleLength++;
            }

            return cycleLength;
        }
    }

    return 0;
}
