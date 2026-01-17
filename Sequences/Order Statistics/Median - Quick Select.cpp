// Time Complexity => O(n2) Worse case | O(n) Average case | O(n) Best case
// Memory Complexity => 
//    	Recursive: O(log n) Average case | O(n) Worst Case
//      Iterative: O(1)
//      nth_Element: O(1)
// Median of a sequence


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

ld median(ll a[], ll n)
{
    srand(time(NULL)); // change rand() from deterministic to probabilistic
    ll k = (n + 1) / 2;
    ll median = quickSelectRecursive(a, 0, n - 1, k - 1);
    if (n % 2 == 0)
    {
        ll median2 = *max_element(a, a + k - 1);
        return (ld) (median + median2) / 2.0;
    }
    return (ld) median;
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

ld median(ll a[], ll n)
{
    srand(time(NULL)); // change rand() from deterministic to probabilistic
    ll k = (n + 1) / 2;
    ll median = quickSelect(a, 0, n - 1, k - 1);
    if (n % 2 == 0)
    {
        ll median2 = *max_element(a, a + k - 1);
        return (ld) (median + median2) / 2.0;
    }
    return (ld) median;
}


------------------------------

// STL nth_element - Quick Select in-built
ld median(ll a[], ll n)
{
    ll k = (n + 1) / 2;
    nth_element(a, a + k - 1, a + n);
    ll median = a[k - 1];
    if (n % 2 == 0)
    {
        ll median2 = *max_element(a, a + k - 1);
        return (ld) (median + median2) / 2.0;
    }
    return (ld) median;
}
