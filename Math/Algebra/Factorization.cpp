// Time Complexity => O(sqrt(n))
// Memory Complexity => O(log n)
// Prime factors of a number

void factorization(ll n, vector<ll> &prime_factors)
{
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        prime_factors.push_back(n);
    }
    return;
}
