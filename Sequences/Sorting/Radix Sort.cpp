// Time Complexity: O(n*k) where k = number of digits in the largest array element 
// Memory Complexity: O(n)
// Stable: Yes
// Mechanism to sort sequences RADIX by RADIX (radix means base) from unit radix to most significant radix of the largest array element


void counting_sort_digit(ll a[], ll n, ll principal)
{
    ll count[10] = {0};
    for (ll i = 0; i < n; i++)
    {
        count[(a[i] / principal) % 10]++;
    }
    for (ll i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    ll temp[n];
    for (ll i = n - 1; i >= 0; i--)
    {
        temp[--count[(a[i] / principal) % 10]] = a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    return;
}
void radix_sort(ll a[], ll n)
{
    ll max_val = *max_element(a, a + n);
    for (ll i = 1; max_val / i > 0; i *= 10)
    {
        counting_sort_digit(a, n, i);
    }
}
