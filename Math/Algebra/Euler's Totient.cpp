// Time Complexity => O(sqrt(n) log(n))
// Memory Complexity => O(1)
// Count of numbers from 1 to n that are co-prime with n.

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            result -= result / i;
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        result -= result / n;
    return result;
}
