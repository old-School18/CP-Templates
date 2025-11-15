// Time Complexity => O(log(min(a,M))
// Memory Complexity => Recursive: O(log min(a,M)) | Iterative: O(1)  [Extended Eulid]
// Determines 'inv' where (a * inv) % M = 1

ll mod(ll a, ll M)
{
    ll absoluteM = abs(M);
    return (a % absoluteM + absoluteM) % absoluteM;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll g = extended_euclid(b, mod(a, b), x, y);
    tie(x, y) = make_tuple(y, x - (a / b) * y);
    return g;
}

ll mod_inverse(ll a, ll M)
{
    ll x, y;
    ll g = extended_euclid(a, M, x, y);
    if (g != 1) {
    	return -1; // No inverse
    }
    return mod(x, M);
}
