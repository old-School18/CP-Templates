// Time Complexity: O(n)
// Memory Complexity: Recursive: O(n) | Iterative: O(1)
// Determine Linked list Cycle head

Node *cycle_head(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}

--------------------------------
Derivation:
Let L1 = length of non-cyclic strip
Let k = distance travelled by slow pointer on cyclic-strip until it met fast pointer
Let C = circumference of the cyclic strip 
Let n = number of cycles completed by the fast pointer before it met slow pointer

At the time they meet,
2*slow_pointer_distance = fast_pointer_distance
=> 2*(L1+k) = L1 + nC + k
=> L1 + k = nC
=> k = nC - L1

We know that after the two pointers met, they are k units away from the cycle head. 
So the above equation implies that if these pointer travel L1 units more, they will reach the head again coz they will complete a cycle. 
And we know that L1 is the length of non-cyclic strip i.e., distance from the linked list head to the cycle head. 
So let's reset one of the two pointers to head and then let's move both pointers one node at a time. They will meet exactly at the cycle head coz both will travel L1 units only. 
