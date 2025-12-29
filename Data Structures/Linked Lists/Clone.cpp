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

Node *clonedList(Node *head)
{
    Node *clonedHead = nullptr, *clonedTemp = nullptr;
    Node *temp = head;

    /* First round: Map original list next pointer to corresponding cloned list node.
        Map cloned list next pointer to corresponding original list node's next node.
    */
    while (temp != nullptr)
    {
        Node *clonedNode = new Node(temp->data);
        Node *nextNode = temp->next;
        clonedNode->next = nextNode;
        temp->next = clonedNode;
        temp = nextNode;
        if (clonedHead == nullptr)
        {
            clonedHead = clonedNode;
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
        Node *originalNext = temp->next->next;
        if (originalNext != nullptr)
        {
            temp->next->next = originalNext->next;
        }
        temp->next = originalNext;
        temp = temp->next;
    }

    return clonedHead;
}
