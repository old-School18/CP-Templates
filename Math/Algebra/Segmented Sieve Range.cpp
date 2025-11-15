// Time Complexity => O(n log log R) where n = R-L+1
// Memory Complexity => O(n + sqrt(R))
// Determine prime numbers in [L,R]

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

void segmented_sieve_range(ll lo, ll hi, vector<ll> &primes_in_range)
{
    ll limit = floor(sqrt((long double) hi)) + 1;
    vector<ll> base_primes;
    sieve(limit, base_primes);
    vector<bool> is_prime(hi - lo + 1, 1);

    // handle 0 and 1 explicitly
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
        // start from the first multiple of p >= lo
        ll start = (lo + p - 1) / p * p;
        if (start < p * p)
            start = p * p;
        for (ll j = start; j <= hi; j += p)
        {
            is_prime[j - lo] = 0;
        }
    }
    for (ll i = lo; i <= hi; i++)
        if (i > 1 && is_prime[i - lo] == true)
            primes_in_range.push_back(i);
    return;
}
