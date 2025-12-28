// Time Complexity => O(sqrt(n))
// Memory Complexity => O(log n)
// Prime factors of a number

void factorization(ll n, vector<ll> &primeFactors)
{
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            primeFactors.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        primeFactors.push_back(n);
    }
    return;
}
