// Time Complexity: O(nlogn)
// Memory Complexity: O(1)
// Stable: No
// Mechanism to sort sequences by first converting the array to max HEAP and then iteratively swapping the root (which has the current max element) with the last element of the shrinking window and then max HEAPIFYING the root again in order to get the next max element


void heapify(ll a[], ll p, ll n)
{
    ll largest = p;
    ll left_child = 2 * p + 1, right_child = 2 * p + 2;

    if (left_child < n && a[largest] < a[left_child])
    {
        largest = left_child;
    }
    if (right_child < n && a[largest] < a[right_child])
    {
        largest = right_child;
    }

    if (largest != p)
    {
        swap(a[largest], a[p]);
        heapify(a, largest, n);
    }
    return;
}

void convert_to_max_heap(ll a[], ll n)
{
    for (ll i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
}

void heap_sort(ll a[], ll n)
{
    convert_to_max_heap(a, n);

    for (ll i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
    return;
}
