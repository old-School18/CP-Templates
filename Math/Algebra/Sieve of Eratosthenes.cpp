// Time Complexity: O(n log log n)
// Determine prime numbers from 1 to n.

void sieve_of_eratosthenes(ll n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return;
}

-----------------------------------
Note:  vector<bool> operates at bit level rather than bytes so 1 element will occupy only 1 bit instead of a byte that a typical boolean variables does. So, this is memory efficient
