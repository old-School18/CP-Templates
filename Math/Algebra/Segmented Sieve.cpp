// Time Complexity: O(n log log n)
// Determine prime numbers from 1 to n for large n.

void sieve(ll n, vector<ll> &prime)
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

    prime.push_back(2);
    for (ll i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
        }
    }
    return;
}

void segmented_sieve(ll n, vector<ll> &all_primes)
{
    ll limit = floor(sqrt(n)) + 1ll;
    vector<ll> prime;
    sieve(limit, prime);
    all_primes = prime;
    bool is_prime[limit + 1];
    ll lo = limit, hi = 2ll * limit;

    while (lo < n)
    {
        if (hi >= n)
            hi = n;
        memset(is_prime, true, sizeof(is_prime));

        for (ll i = 0; i < (ll) prime.size(); i++)
        {
            ll lo_lim = floor(lo / prime[i]) * prime[i];
            if (lo_lim < lo)
                lo_lim += prime[i];
            for (ll j = lo_lim; j <= hi; j += prime[i])
                is_prime[j - lo] = false;
        }

        for (ll i = lo; i <= hi; i++)
            if (is_prime[i - lo] == true)
                all_primes.push_back(i);

        lo += limit;
        hi += limit;
    }
    return;
}
