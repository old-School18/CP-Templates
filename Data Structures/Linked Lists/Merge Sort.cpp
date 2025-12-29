// Time Complexity: O(n)
// Memory Complexity: O(1)
// Determine whether a linked list is palindrome or not

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
bool isPalindrome(Node *head)
{
    Node *middleNode = tortoiseHare(head);
    Node *tail = reverseLL(middleNode);

    while (head->data == tail->val)
    {
        if (tail == middleNode)
        {
            return true;
        }
        head = head->next;
        tail = tail->next;
    }
    return false;
}
