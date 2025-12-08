// Time Complexity: O(n2) Worst | O(nlogn) Average | O(nlogn) Best 
// Memory Complexity: O(n)
// Stable: Yes
// Mechanism to sort sequences by identifying the appropriate position for a given element and then dividing the elements before and after the given element into smaller sequences and recursively solving for them

ll find_pivot(ll a[], ll l, ll r)
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

void quick_sort_recursion(ll a[], ll l, ll r)
{
    if (l < r)
    {
        ll pivot = find_pivot(a, l, r);
        quick_sort_recursion(a, l, pivot - 1);
        quick_sort_recursion(a, pivot + 1, r);
    }
}

void quick_sort(ll a[], ll n)
{
    quick_sort_recursion(a, 0, n - 1);
}
