// Time Complexity => O(sqrt(n))
// Memory Complexity => O(n)
// Integer factors of a number

void factors(ll n, vector<ll> &factors)
{
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (n / i != i)
                factors.push_back(n / i);
        }
    }
    return;
}
