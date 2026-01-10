// Time Complexity => O(n)
// Memory Complexity => O(n)
// Methods to determine next/previous smaller/larger elements in a sequence

vector<ll> preProcess(ll a[], ll n, bool isForward, bool isLargeSearch)
{
    vector<ll> result(n);
    stack<ll> stk;
    for (ll i = (isForward ? 0 : n - 1); isForward ? (i < n) : (i >= 0); i += (isForward ? 1 : -1))
    {
        while (!stk.empty() &&
               ((isForward && ((isLargeSearch && a[stk.top()] <= a[i]) || (!isLargeSearch && a[stk.top()] >= a[i]))) ||
                (!isForward && ((isLargeSearch && a[stk.top()] < a[i]) || (!isLargeSearch && a[stk.top()] > a[i])))))
        {
            stk.pop();
        }

        result[i] = (!stk.empty() ? stk.top() : (isForward ? -1 : n));
        stk.push(i);
    }
    return result;
}

vector<ll> previousSmaller(ll a[], ll n)
{
    return preProcess(a, n, true, false);
}

vector<ll> previousLarger(ll a[], ll n)
{
    return preProcess(a, n, true, true);
}

vector<ll> nextSmaller(ll a[], ll n)
{
    return preProcess(a, n, false, false);
}

vector<ll> nextLarger(ll a[], ll n)
{
    return preProcess(a, n, false, true);
}
