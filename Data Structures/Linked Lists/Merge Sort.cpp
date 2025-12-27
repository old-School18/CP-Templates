// Time Complexity: O(nlog n)
// Memory Complexity: O(log n)
// Merge sort algorithm for linked lists

Node *tortoise_hare(Node *head)
{
    Node *slow = head, *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *merged_list_head = new Node(-1);
    Node *temp = merged_list_head;

    while (left != nullptr && right != nullptr)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if (left != nullptr)
    {
        temp->next = left;
    }
    if (right != nullptr)
    {
        temp->next = right;
    }

    return merged_list_head->next;
}

Node *merge_sort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *middle_node = tortoise_hare(head);
    Node *left = head;
    Node *right = middle_node->next;
    middle_node->next = nullptr;

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}
