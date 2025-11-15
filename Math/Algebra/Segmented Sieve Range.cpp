// Time Complexity: O(n log log R) where n = R-L+1
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

void segmented_sieve_range(ll lo, ll hi, vector<ll> &primes_in_range)
{
    ll limit = floor(sqrt(hi)) + 1;
    vector<ll> prime;
    sieve(limit, prime);
    primes_in_range = prime;
    bool is_prime[hi - lo + 1];
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
        if (i - lo > 1 && is_prime[i - lo] == true)
            primes_in_range.push_back(i);
    return;
}
