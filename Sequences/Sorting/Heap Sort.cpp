// Time Complexity: O(nlogn)
// Memory Complexity: O(1)
// Stable: No
// Mechanism to sort sequences by repeatedly max HEAPIFYING the array elements and assigning the root (which has current max value) to the last element of the shrinking window


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
void heap_sort(ll a[], ll n)
{
    for (ll i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
    return;
}
