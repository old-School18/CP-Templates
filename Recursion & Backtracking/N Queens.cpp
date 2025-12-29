// Time Complexity => O(N!)
// Memory Complexity => O(N^2)
// Place N queens in an N*N chessboard such that no two queens can attack each other

// Iterative strategy
bool isValidPosition(ll row, ll col, ll n, vector<bool> &isColVisited, vector<bool> &isLeftDiagVisited,
                     vector<bool> &isRightDiagVisited)
{
    return !isColVisited[col] && !isLeftDiagVisited[n - 1 + (row - col)] && !isRightDiagVisited[row + col];
}
void nQueensBacktrack(ll n, vector<vector<string>> &results, vector<string> &temp, vector<bool> &isColVisited,
                      vector<bool> &isLeftDiagVisited, vector<bool> &isRightDiagVisited, ll row)
{
    if (row == n)
    {
        results.push_back(temp);
        return;
    }

    for (ll col = 0; col < n; col++)
    {
        if (isValidPosition(row, col, n, isColVisited, isLeftDiagVisited, isRightDiagVisited))
        {
            temp[row][col] = 'Q';
            isColVisited[col] = isLeftDiagVisited[n - 1 + (row - col)] = isRightDiagVisited[row + col] = true;
            nQueensBacktrack(n, results, temp, isColVisited, isLeftDiagVisited, isRightDiagVisited, row + 1);
            isColVisited[col] = isLeftDiagVisited[n - 1 + (row - col)] = isRightDiagVisited[row + col] = false;
            temp[row][col] = '.';
        }
    }
    return;
}

vector<vector<string>> nQueens(ll n)
{
    vector<vector<string>> results;
    vector<string> temp(n, string(n, '.'));
    vector<bool> isColVisited(n, false);
    vector<bool> isLeftDiagVisited(2ll * n - 1, false);
    vector<bool> isRightDiagVisited(2ll * n - 1, false);

    nQueensBacktrack(n, results, temp, isColVisited, isLeftDiagVisited, isRightDiagVisited, 0);
    return results;
}

-----------------------
Reference:
https://leetcode.com/problems/n-queens/
