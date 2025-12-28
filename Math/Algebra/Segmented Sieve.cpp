// Time Complexity => O(n log log n)
// Memory Complexity => O(sqrt(n))
// Determine prime numbers from 1 to n for large n.

void sieve(ll n, vector<ll> &prime)
{
    vector<char> isPrime(n + 1, 1);
    isPrime[0] = isPprime[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    if (n >= 2)
    {
        prime.push_back(2);
    }
    for (ll i = 3; i <= n; i += 2)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
        }
    }
    return;
}

void segmentedSieve(ll n, vector<ll> &allPrimes)
{
    ll limit = floor(sqrt((long double) n)) + 1;
    vector<ll> basePrimes;
    sieve(limit, basePrimes);
    allPrimes = basePrimes;
    ll lo = limit + 1, hi = 2ll * limit;

    while (lo <= n)
    {
        if (hi >= n)
            hi = n;
        vector<char> isPrime(hi - lo + 1, 1);

        if (lo == 0)
        {
            isPrime[0] = 0; // 0 not prime
            if (hi >= 1)
                isPrime[1] = 0; // 1 not prime
        }
        else if (lo == 1)
        {
            isPrime[0] = 0; // 1 not prime
        }

        for (ll p : basePrimes)
        {
            ll start = (lo + p - 1) / p * p;
            if (start < p * p)
                start = p * p;
            for (ll j = start; j <= hi; j += p)
                isPrime[j - lo] = 0;
        }

        for (ll i = lo; i <= hi; i++)
            if (isPrime[i - lo])
                allPrimes.push_back(i);

        lo += limit;
        hi += limit;
    }
    return;
}
