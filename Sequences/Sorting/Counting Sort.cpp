// Time Complexity: O(n+m) where m — maximum element in the sequence
// Memory Complexity: O(n+m)
// Stable: Yes
// Mechanism to sort sequences by COUNTING number of elements less than equal to each element in the sequence

void counting_sort(ll a[], ll n)
{
    ll max_elem = a[0];
    for (ll i = 0; i < n; i++)
    {
        max_elem = max(max_elem, a[i]);
    }

    ll count[max_elem + 1] = {0};

    for (ll i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (ll i = 1; i <= max_elem; i++)
    {
        count[i] += count[i - 1];
    }

    ll temp[n];
    for (ll i = n - 1; i >= 0; i--)
    {
        temp[--count[a[i]]] = a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    return;
}
