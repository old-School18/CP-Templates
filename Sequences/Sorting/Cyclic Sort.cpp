// Time Complexity: O(n)
// Memory Complexity: O(1)
// Stable: No
// Mechanism to sort permutation arrays by swapping elements to their respective indices in CYCLES


void cyclic_sort(ll a[], ll n)
{
    // a[] -> [1,n]
    for (ll i = 0; i < n; i++)
    {
        a[i]--;
    }
	
    ll idx = 0;
    while (idx < n)
    {
        while (idx != a[idx])
        {
            swap(a[idx], a[a[idx]]);
        }
        idx++;
    }
    return;
}
