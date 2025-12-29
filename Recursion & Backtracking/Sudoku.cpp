// Time Complexity => O(9^81) for a 9*9 board 
// Memory Complexity => O(81)
// Solves a 9*9 sudoku puzzle. Puzzle board size can be varied in the algorithm

// Iterative strategy
bool isValid(vector<vector<char>> &board, ll x, ll y, char c)
{
    for (ll i = 0; i < 9; i++)
    {
        if (board[i][y] == c || board[x][i] == c)
        {
            return false;
        }
    }

    for (ll i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
    {
        for (ll j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
        {
            if (board[i][j] == c)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudokuBacktrack(vector<vector<char>> &board, ll row)
{

    for (ll i = row; i < 9; i++)
    {
        for (ll j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (sudokuBacktrack(board, i))
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudoku(vector<vector<char>> &board)
{
    sudokuBacktrack(board, 0);
    return;
}
