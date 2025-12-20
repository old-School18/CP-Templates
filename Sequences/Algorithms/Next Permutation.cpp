// Time Complexity: O(n)
// Memory Complexity: O(1)
// Next permutation of a sequence


void next_permutation(ll a[], ll n)
{
    for (ll i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            ll left = i + 1, right = n - 1;
            while (left < right)
            {
                swap(a[left++], a[right--]);
            }
            for (ll j = i + 1; j < n; j++)
            {
                if (a[i] < a[j])
                {
                    swap(a[i], a[j]);
                    return;
                }
            }
        }
    }

    // if given sequence is in decreasing order i.e., last permutation then return first permutation
    for (ll i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - 1 - i]);
    }

    return;
}
