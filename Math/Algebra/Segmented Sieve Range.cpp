// Time Complexity => O(n log log R) where n = R-L+1
// Memory Complexity => O(n + sqrt(R))
// Determine prime numbers in [L,R]

void sieve(ll n, vector<ll> &prime)
{
    vector<char> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
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

void segmentedSieveRange(ll lo, ll hi, vector<ll> &primesInRange)
{
    ll limit = floor(sqrt((long double) hi)) + 1;
    vector<ll> basePrimes;
    sieve(limit, basePrimes);
    vector<char> isPrime(hi - lo + 1, 1);

    // handle 0 and 1 explicitly
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
        // start from the first multiple of p >= lo
        ll start = (lo + p - 1) / p * p;
        if (start < p * p)
            start = p * p;
        for (ll j = start; j <= hi; j += p)
        {
            isPrime[j - lo] = 0;
        }
    }
    for (ll i = lo; i <= hi; i++)
        if (i > 1 && isPrime[i - lo])
            primesInRange.push_back(i);
    return;
}
