// Time Complexity => O(log n)
// Memory Complexity => O(1)
// Binary number to Decimal conversion

ll binaryToDecimal(vector<ll> &binary)
{
    ll decimal = 0;
    for (auto &p : binary)
    {
        decimal = decimal * 2ll + p;
    }
    return decimal;
}
