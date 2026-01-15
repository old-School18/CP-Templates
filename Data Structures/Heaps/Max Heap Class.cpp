// Time Complexity => O(n) minElement | O(1) maxElement | O(log n) remaining operations
// Memory Complexity => O(n)
// Max Heap class

class MaxHeap
{
  public:
    vector<ll> heap;
    ll size;

    MaxHeap()
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
        ll largest = idx;
        ll left = leftChild(idx);
        ll right = rightChild(idx);

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != idx)
        {
            swap(heap[idx], heap[largest]);
            heapify(largest);
        }
    }

    void siftUp(ll idx)
    {
        if (idx && heap[idx] > heap[parent(idx)])
        {
            swap(heap[idx], heap[parent(idx)]);
            siftUp(parent(idx));
        }
        return;
    }

    ll minElement()
    {
        ll ans = LLONG_MAX;
        for (ll i = size / 2; i < size; i++)
            ans = min(ans, heap[i]);
        return ans;
    }

    ll maxElement()
    {
        return !isEmpty() ? heap[0] : LLONG_MIN;
    }

    ll extractMaxElement()
    {
        if (isEmpty())
            return LLONG_MIN;
        ll maxElement = heap[0];
        swap(heap[0], heap[--size]);
        heap.pop_back();
        heapify(0);
        return maxElement;
    }

    void changeKey(ll idx, ll newValue)
    {
        if (idx >= size)
            return;

        if (heap[idx] < newValue)
        {
            heap[idx] = newValue;
            siftUp(idx);
        }
        else if (heap[idx] > newValue)
        {
            heap[idx] = newValue;
            heapify(idx);
        }
        return;
    }

    void deleteKey(ll idx)
    {
        changeKey(idx, LLONG_MAX);
        extractMaxElement();
        return;
    }
};
