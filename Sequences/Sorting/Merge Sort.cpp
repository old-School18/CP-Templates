// Time Complexity: O(nlogn)
// Memory Complexity: O(n)
// Stable: Yes
// Mechanism to sort sequences by dividing into smaller sequences and recursively MERGING them

void merge(ll a[], ll l, ll r)
{
    ll mid = l + (r - l) / 2;
    ll n1 = mid - l + 1, n2 = r - mid;
    ll left[n1], right[n2];

    for (ll i = l; i <= mid; i++)
    {
        left[i - l] = a[i];
    }
    for (ll i = mid + 1; i <= r; i++)
    {
        right[i - mid - 1] = a[i];
    }

    ll curr_idx = l;
    ll x = 0, y = 0;

    while (x < n1 && y < n2)
    {
        a[curr_idx++] = (left[x] <= right[y]) ? left[x++] : right[y++];
    }
    while (x < n1)
    {
        a[curr_idx++] = left[x++];
    }
    while (y < n2)
    {
        a[curr_idx++] = right[y++];
    }

    return;
}

void merge_sort_recursion(ll a[], ll l, ll r)
{
    ll mid = l + (r - l) / 2;
    if (l < r)
    {
        merge_sort_recursion(a, l, mid);
        merge_sort_recursion(a, mid + 1, r);
        merge(a, l, r);
    }
}

void merge_sort(ll a[], ll n)
{
    merge_sort_recursion(a, 0, n - 1);
}
