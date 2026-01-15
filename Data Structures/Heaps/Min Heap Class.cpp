// Time Complexity => O(1) minElement | O(n) maxElement | O(log n) remaining operations
// Memory Complexity => O(n)
// Min Heap class

class MinHeap
{
  public:
    vector<ll> heap;
    ll size;

    MinHeap()
    {
        this->size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    ll parent(ll idx)
    {
        return (idx - 1) / 2;
    }

    ll leftChild(ll idx)
    {
        return 2 * idx + 1;
    }

    ll rightChild(ll idx)
    {
        return 2 * idx + 2;
    }

    void insert(ll x)
    {
        ll idx = size++;
        heap.push_back(x);

        siftUp(idx);
    }

    // sift-down
    void heapify(ll idx)
    {
        ll smallest = idx;
        ll left = leftChild(idx);
        ll right = rightChild(idx);

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != idx)
        {
            swap(heap[idx], heap[smallest]);
            heapify(smallest);
        }
    }

    void siftUp(ll idx)
    {
        if (idx && heap[idx] < heap[parent(idx)])
        {
            swap(heap[idx], heap[parent(idx)]);
            siftUp(parent(idx));
        }
        return;
    }

    ll minElement()
    {
        return !isEmpty() ? heap[0] : LLONG_MAX;
    }

    ll maxElement()
    {
        ll ans = LLONG_MIN;
        for (ll i = size / 2; i < size; i++)
            ans = max(ans, heap[i]);
        return ans;
    }

    ll extractMinElement()
    {
        if (isEmpty())
            return LLONG_MAX;
        ll minElement = heap[0];
        swap(heap[0], heap[--size]);
        heap.pop_back();
        heapify(0);
        return minElement;
    }

    void changeKey(ll idx, ll newValue)
    {
        if (idx >= size)
            return;

        if (heap[idx] < newValue)
        {
            heap[idx] = newValue;
            heapify(idx);
        }
        else if (heap[idx] > newValue)
        {
            heap[idx] = newValue;
            siftUp(idx);
        }
        return;
    }

    void deleteKey(ll idx)
    {
        changeKey(idx, LLONG_MIN);
        extractMinElement();
        return;
    }
};
