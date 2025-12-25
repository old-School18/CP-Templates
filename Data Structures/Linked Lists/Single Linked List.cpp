class Node
{
  public:
    ll data;
    Node *next;

    Node(ll data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(ll data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
