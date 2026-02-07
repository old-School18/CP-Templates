// Time Complexity: O(n)
// Memory Complexity: O(h) DFS | O(w) BFS where h = tree height, w = tree width
// Height of a binary tree

// Recursive - DFS
ll heightBTRecursive(BT *root)
{
    if (!root)
    {
        return 0;
    }

    return 1ll + max(heightBTRecursive(root->left), heightBTRecursive(root->right));
}

------------------------
// Iterative - BFS
ll heightBT(BT *root)
{
    ll levels = 0;
    queue<BT *> qe;

    if (root)
    {
        qe.push(root);
    }

    while (!qe.empty())
    {
        ll currentLevelSize = qe.size();
        while (currentLevelSize--)
        {
            auto p = qe.front();
            qe.pop();
            if (p->left)
                qe.push(p->left);
            if (p->right)
                qe.push(p->right);
        }

        levels++;
    }
    return levels;
}

------------------------
// Iterative - BFS aliter
ll heightBT(BT *root)
{
    ll levels = 0;
    queue<BT *> qe;

    if (root)
    {
        qe.push(root);
        qe.push(NULL);
    }

    while (!qe.empty())
    {
        auto p = qe.front();
        qe.pop();
        if (p)
        {
            if (p->left)
                qe.push(p->left);
            if (p->right)
                qe.push(p->right);
        }
        else
        {
            if (!qe.empty())
            {
                qe.push(NULL);
            }
            levels++;
        }
    }
    return levels;
}


------------------------
// Iterative - DFS
ll heightBT(BT *root)
{
    ll height = 0;
    stack<pair<BT *, ll>> stk;

    if (root)
    {
        stk.push({root, 1});
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();
        height = max(height, p.second);

        if (p.first->right)
        {
            stk.push({p.first->right, p.second + 1});
        }
        if (p.first->left)
        {
            stk.push({p.first->left, p.second + 1});
        }
    }
    return height;
}
