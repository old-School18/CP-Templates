// Time Complexity: O(n)
// Memory Complexity: O(1)
// Clone a linked list that has next and random pointers

class Node
{
  public:
    ll data;
    Node *next;
    Node *random;

    Node(ll data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }

    Node(ll data, Node *next)
    {
        this->data = data;
        this->next = next;
        this->random = nullptr;
    }

    Node(ll data, Node *next, Node *random)
    {
        this->data = data;
        this->next = next;
        this->random = random;
    }
};

Node *cloned_list(Node *head)
{
    Node *cloned_head = nullptr, *cloned_temp = nullptr;
    Node *temp = head;

    /* First round: Map original list next pointer to corresponding cloned list node.
        Map cloned list next pointer to corresponding original list node's next node.
    */
    while (temp != nullptr)
    {
        Node *cloned_node = new Node(temp->data);
        Node *next_node = temp->next;
        cloned_node->next = next_node;
        temp->next = cloned_node;
        temp = next_node;
        if (cloned_head == nullptr)
        {
            cloned_head = cloned_node;
        }
    }

    temp = head;

    /* Second round: Map cloned list nodes' random pointers to corresponding
        cloned list nodes.
    */
    while (temp != nullptr)
    {
        if (temp->random != nullptr)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    temp = head;

    /* Third round: Map original list and cloned list nodes' next pointers
        to the corresponding next nodes.
    */
    while (temp != nullptr)
    {
        Node *original_next = temp->next->next;
        if (original_next != nullptr)
        {
            temp->next->next = original_next->next;
        }
        temp->next = original_next;
        temp = temp->next;
    }

    return cloned_head;
}
