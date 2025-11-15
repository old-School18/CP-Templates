// Time Complexity => O(n log log n)
// Memory Complexity => O(n)
// Determine prime numbers from 1 to n.

void sieve_of_eratosthenes(ll n)
{
    vector<char> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

    return;
}

-----------------------------------
Note:  Use vector<char> for time efficiency and vector<bool> for memory efficiency. vector<bool> operates at bit level rather than bytes so 1 element will occupy only 1 bit instead of a byte that a typical boolean variables does. So, this is memory efficient
