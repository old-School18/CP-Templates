// Time Complexity: O(n*k)
// Memory Complexity: O(k)
// Determins k-majority elements of a sequenece i.e., elements that occur more than (n/k) times


vector<ll> boyer_moore(ll a[], ll n, ll k)
{
    vector<pair<ll, ll>> candidates;

    // Phase 1: candidate selection
    for (ll i = 0; i < n; i++)
    {
        bool found = false;

        for (auto &p : candidates)
        {
            if (p.first == a[i])
            {
                p.second++;
                found = true;
                break;
            }
        }

        if (found)
            continue;

        if ((ll) candidates.size() < k - 1)
        {
            candidates.push_back({a[i], 1});
        }
        else
        {
            for (auto &p : candidates)
            {
                p.second--;
            }

            // remove zero-count candidates
            candidates.erase(remove_if(candidates.begin(), candidates.end(), [](auto &p) { return p.second == 0; }),
                             candidates.end());
        }
    }

    // Phase 2: verification
    for (auto &p : candidates)
        p.second = 0;

    for (ll i = 0; i < n; i++)
    {
        for (auto &p : candidates)
        {
            if (p.first == a[i])
            {
                p.second++;
                break;
            }
        }
    }

    vector<ll> result;
    ll threshold = n / k;

    for (auto &p : candidates)
    {
        if (p.second > threshold)
            result.push_back(p.first);
    }

    return result;
}
