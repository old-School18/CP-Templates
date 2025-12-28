// Time Complexity => O(sqt(n)/6)
// Memory Complexity => O(1)
// Using the property that every prime no. is of the 
// form (6n-1) or (6n+1)

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
