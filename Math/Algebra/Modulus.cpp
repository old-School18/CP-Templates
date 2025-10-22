// Time Complexity: O(1)
// Resultant value is always between 0 and M-1 even when divisor or dividend is negative

ll mod(ll a, ll M)
{
    ll absoluteM = abs(M);
    return (a % absoluteM + absoluteM) % absoluteM;
}
