// Time Complexity => O(n.m.3^L) where L – length of the word
// Memory Complexity => O(n.m + L)
// Determine if a given word is present in a grid

// Mark-unmark Strategy
bool isValid(vector<vector<char>> &grid, string &word, ll n, ll m, vector<vector<bool>> &vis, ll i, ll j, ll idx)
{
    return (i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1 && grid[i][j] == word[idx] && !vis[i][j]);
}

bool wordSearchBacktrack(vector<vector<char>> &grid, string &word, ll n, ll m, vector<vector<bool>> &vis, ll i, ll j,
                         ll idx)
{
    if (idx == (ll) word.size())
    {
        return true;
    }

    if (!isValid(grid, word, n, m, vis, i, j, idx))
    {
        return false;
    }

    vis[i][j] = true;
    bool found = wordSearchBacktrack(grid, word, n, m, vis, i, j + 1, idx + 1) ||
                 wordSearchBacktrack(grid, word, n, m, vis, i, j - 1, idx + 1) ||
                 wordSearchBacktrack(grid, word, n, m, vis, i + 1, j, idx + 1) ||
                 wordSearchBacktrack(grid, word, n, m, vis, i - 1, j, idx + 1);
    vis[i][j] = false;
    return found;
}

bool wordSearch(vector<vector<char>> &grid, string &word)
{
    ll n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (wordSearchBacktrack(grid, word, n, m, vis, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

---------------------
Reference:
https://leetcode.com/problems/word-search/
