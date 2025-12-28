// Time Complexity => O(n)
// Memory Complexity => O(n)
// Determine prime numbers till n in linear time. 
// Also determines lowest prime factors of all numbers till n

void linearSieve(ll n, vector<ll> &primes)
{
    vector<ll> lp(n + 1);

    for (ll i = 2; i <= n; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            primes.pb(i);
        }
        for (ll j = 0; j < (ll) primes.size() && primes[j] * i <= n && primes[j] <= lp[i]; j++)
        {
            lp[primes[j] * i] = primes[j];
        }
    }

    return;
}
