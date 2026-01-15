// Time Complexity => O(n2) Worse case | O(n) Averase case | O(n) Best case 
// Memory Complexity => O(n)
// kth smallest element in a sequence

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

ll quickSelectRecurse(ll a[], ll l, ll r, ll k)
{
    if (l <= r)
    {
        ll pivot = findPivot(a, l, r);
        if (pivot < k)
        {
            return quickSelectRecurse(a, pivot + 1, r, k);
        }
        else if (pivot == k)
        {
            return a[pivot];
        }
        else
        {
            return quickSelectRecurse(a, l, pivot - 1, k);
        }
    }
    return -1;
}

ll quickSelect(ll a[], ll n, ll k)
{
    return quickSelectRecurse(a, 0, n - 1, k - 1);
}
