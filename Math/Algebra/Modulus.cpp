// Time Complexity: O(1)

ll mod(ll a, ll M)
{
    ll absoluteM = abs(M);
    return (a % absoluteM + absoluteM) % absoluteM;
}
