// Time Complexity => O(n log log n)
// Memory Complexity => O(sqrt(n))
// Determine prime numbers from 1 to n for large n.

void sieve(ll n, vector<ll> &prime)
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

    if (n >= 2)
    {
        prime.push_back(2);
    }
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
    ll limit = floor(sqrt((long double) n)) + 1;
    vector<ll> base_primes;
    sieve(limit, base_primes);
    all_primes = base_primes;
    ll lo = limit, hi = 2ll * limit;

    while (lo < n)
    {
        if (hi >= n)
            hi = n;
        vector<char> is_prime(hi - lo + 1, 1);

        if (lo == 0)
        {
            is_prime[0] = 0; // 0 not prime
            if (hi >= 1)
                is_prime[1] = 0; // 1 not prime
        }
        else if (lo == 1)
        {
            is_prime[0] = 0; // 1 not prime
        }

        for (ll p : base_primes)
        {
            ll start = (lo + p - 1) / p * p;
            if (start < p * p)
                start = p * p;
            for (ll j = start; j <= hi; j += p)
                is_prime[j - lo] = 0;
        }

        for (ll i = lo; i <= hi; i++)
            if (is_prime[i - lo])
                all_primes.push_back(i);

        lo += limit;
        hi += limit;
    }
    return;
}
