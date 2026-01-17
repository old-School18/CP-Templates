// Time Complexity => O(n2) Worse case | O(n) Average case | O(n) Best case
// Memory Complexity => 
//    	Recursive: O(log n) Average case | O(n) Worst Case
//      Iterative: O(1)
//      nth_Element: O(1)
// kth largest element in a sequence.


// Quick Select Algorithm - Recursive
ll findPivot(ll a[], ll l, ll r)
{
    ll idx = l + rand() % (r - l + 1);
    swap(a[idx], a[r]);
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

ll quickSelectRecursive(ll a[], ll l, ll r, ll k)
{
    if (l <= r)
    {
        ll pivot = findPivot(a, l, r);
        if (pivot < k)
        {
            return quickSelectRecursive(a, pivot + 1, r, k);
        }
        else if (pivot == k)
        {
            return a[pivot];
        }
        else
        {
            return quickSelectRecursive(a, l, pivot - 1, k);
        }
    }
    return -1;
}

ll kthLargest(ll a[], ll n, ll k)
{
    srand(time(NULL)); // change rand() from deterministic to probabilistic
    return quickSelectRecursive(a, 0, n - 1, n - k);
}

----------------------------

// Quick Select Algorithm - Iterative
ll findPivot(ll a[], ll l, ll r)
{
    ll idx = l + rand() % (r - l + 1);
    swap(a[idx], a[r]);
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

ll quickSelect(ll a[], ll l, ll r, ll k)
{
    while (l <= r)
    {
        ll pivot = findPivot(a, l, r);
        if (pivot < k)
        {
            l = pivot + 1;
        }
        else if (pivot == k)
        {
            return a[pivot];
        }
        else
        {
            r = pivot - 1;
        }
    }
    return -1;
}

ll kthLargest(ll a[], ll n, ll k)
{
    srand(time(NULL)); // change rand() from deterministic to probabilistic
    return quickSelect(a, 0, n - 1, n - k);
}

------------------------------

// STL nth_element - Quick Select in-built
ll kthLargest(ll a[], ll n, ll k)
{
    nth_element(a, a + n - k, a + n);
    return a[n - k];
}
