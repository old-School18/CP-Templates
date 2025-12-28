// Time Complexity => O(1)
// Memory Complexity => O(1)
// Resultant value has the same sign as the divisor i.e., M

ll modMathematical(ll a, ll M)
{
    return a - (a / M) * M;
}
