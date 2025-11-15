// Time Complexity => O(sqrt(n))
// Memory Complexity => O(n)
// Integer factors of a number

vector<ll> factors(ll n)
{
    vector<ll> v;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i != i)
                v.push_back(n / i);
        }
    }
    return v;
}
