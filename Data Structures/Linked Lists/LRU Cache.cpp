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

class DllList
{
  public:
    DoubleNode *head, *tail;

    DllList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addNode(DoubleNode *&node)
    {
        if (this->head == nullptr)
        {
            this->head = this->tail = node;
        }
        else
        {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = this->tail->next;
        }
    }

    void detachNode(DoubleNode *&node)
    {
        if (this->head == node)
        {
            this->head = this->head->next;
        }
        if (this->tail == node)
        {
            this->tail = this->tail->prev;
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

    void popHead()
    {
        DoubleNode *currHead = this->head;
        this->head = this->head->next;

        if (this->head != nullptr)
            this->head->prev = nullptr;

        if (this->tail == currHead)
            this->tail = nullptr;
        delete currHead;
    }
};

class LRUCache
{
  public:
    ll capacity;
    unordered_map<ll, DoubleNode *> cache;
    DllList *dllList;
    LRUCache(ll capacity)
    {
        this->capacity = capacity;
        this->dllList = new DllList();
    }

    ll get(ll key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        dllList->detachNode(cache[key]);
        dllList->addNode(cache[key]);
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
                cache.erase(dllList->head->key);
                dllList->popHead();
            }
            cache[key] = new DoubleNode(key, value);
        }
        else
        {
            cache[key]->data = value;
            dllList->detachNode(cache[key]);
        }
        dllList->addNode(cache[key]);
    }
};
