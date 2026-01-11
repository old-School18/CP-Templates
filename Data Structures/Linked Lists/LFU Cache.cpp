// Time Complexity => O(1)
// Memory Complexity => O(n)
// Least Frequently Used (LFU) cache implementation. Ties broken by popping out LRU

class DoubleNode
{
  public:
    ll key;
    ll data;
    ll frequency;
    DoubleNode *prev;
    DoubleNode *next;

    DoubleNode(ll key, ll data, ll frequency)
    {
        this->key = key;
        this->data = data;
        this->frequency = frequency;
        this->prev = nullptr;
        this->next = nullptr;
    }

    void increaseFrequency()
    {
        this->frequency++;
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

class LFUCache
{
  public:
    ll capacity;
    ll minFrequency;
    unordered_map<ll, DoubleNode *> cache;
    unordered_map<ll, DllList *> frequencyMap;
    LFUCache(ll capacity)
    {
        this->capacity = capacity;
        this->minFrequency = 0;
    }

    ll get(ll key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        frequencyMap[cache[key]->frequency]->detachNode(cache[key]);
        if (cache[key]->frequency == minFrequency && frequencyMap[minFrequency]->head == nullptr)
            minFrequency++;
        cache[key]->increaseFrequency();
        if (frequencyMap.find(cache[key]->frequency) == frequencyMap.end())
            frequencyMap[cache[key]->frequency] = new DllList();
        frequencyMap[cache[key]->frequency]->addNode(cache[key]);
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
                cache.erase(frequencyMap[minFrequency]->head->key);
                frequencyMap[minFrequency]->popHead();
            }
            cache[key] = new DoubleNode(key, value, 1);
            minFrequency = 1;
        }
        else
        {
            cache[key]->data = value;
            frequencyMap[cache[key]->frequency]->detachNode(cache[key]);
            if (cache[key]->frequency == minFrequency && frequencyMap[minFrequency]->head == nullptr)
                minFrequency++;
            cache[key]->increaseFrequency();
        }
        if (frequencyMap.find(cache[key]->frequency) == frequencyMap.end())
            frequencyMap[cache[key]->frequency] = new DllList();
        frequencyMap[cache[key]->frequency]->addNode(cache[key]);
    }
};
