// Time Complexity: O(1)
// Resultant value has the same sign as the divisor i.e., a

ll mod_mathematical(ll a, ll M)
{
    return a - (a / M) * M;
}
