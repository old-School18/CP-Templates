// Time Complexity => O(1)
// Memory Complexity => O(n)
// Least Recently Used (LRU) cache implementation

class DoubleNode
{
  public:
    ll key;
    ll data;
    DoubleNode *prev;
    DoubleNode *next;

    DoubleNode(ll key, ll data)
    {
        this->key = key;
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache
{
  public:
    ll capacity;
    unordered_map<ll, DoubleNode *> cache;
    DoubleNode *head, *tail;
    LRUCache(ll capacity)
    {
        this->capacity = capacity;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addNode(DoubleNode *&node, DoubleNode *&head, DoubleNode *&tail)
    {
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
    }

    void detachNode(DoubleNode *&node, DoubleNode *&head, DoubleNode *&tail)
    {
        if (head == node)
        {
            head = head->next;
        }
        if (tail == node)
        {
            tail = tail->prev;
        }
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }

        node->prev = node->next = nullptr;
    }

    void popHead(DoubleNode *&head, DoubleNode *&tail)
    {
        DoubleNode *currHead = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        if (tail == currHead)
            tail = nullptr;
        delete currHead;
    }

    ll get(ll key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        detachNode(cache[key], head, tail);
        addNode(cache[key], head, tail);
        return cache[key]->data;
    }

    void put(ll key, ll value)
    {
        if (capacity == 0)
            return;
        if (cache.find(key) == cache.end())
        {
            if (cache.size() == capacity)
            {
                cache.erase(head->key);
                popHead(head, tail);
            }
            cache[key] = new DoubleNode(key, value);
        }
        else
        {
            cache[key]->data = value;
            detachNode(cache[key], head, tail);
        }
        addNode(cache[key], head, tail);
    }
};
