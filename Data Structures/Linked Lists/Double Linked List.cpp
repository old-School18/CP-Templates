class DoubleNode
{
  public:
    ll data;
    DoubleNode *prev;
    DoubleNode *next;

    DoubleNode(ll data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    DoubleNode(ll data, DoubleNode *prev, DoubleNode *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};
