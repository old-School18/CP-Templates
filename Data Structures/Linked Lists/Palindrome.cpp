// Time Complexity: O(n)
// Memory Complexity: O(1)
// Determine whether a linked list is palindrome or not

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
bool is_palindrome(Node *head)
{
    Node *middle_node = tortoise_hare(head);
    Node *tail = reverse_LL(middle_node);

    while (head->data == tail->val)
    {
        if (tail == middle_node)
        {
            return true;
        }
        head = head->next;
        tail = tail->next;
    }
    return false;
}
