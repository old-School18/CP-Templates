// Time Complexity: O(n2) Worst | O(nlogn) Average | O(nlogn) Best 
// Memory Complexity: O(n)
// Stable: Yes
// Mechanism to sort sequences by identifying the appropriate position for a given element and then dividing the elements before and after the given element into smaller sequences and recursively solving for them

ll findPivot(ll a[], ll l, ll r)
{
    ll pivot = l;

    for (ll i = l; i < r; i++)
    {
        if (a[i] < a[r])
        {
            swap(a[pivot++], a[i]);
        }
    }
    swap(a[pivot], a[r]);
    return pivot;
}

void quickSortRecurse(ll a[], ll l, ll r)
{
    if (l < r)
    {
        ll pivot = findPivot(a, l, r);
        quickSortRecurse(a, l, pivot - 1);
        quickSortRecurse(a, pivot + 1, r);
    }
}

void quickSort(ll a[], ll n)
{
    quickSortRecurse(a, 0, n - 1);
}
