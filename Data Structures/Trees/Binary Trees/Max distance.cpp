// Time Complexity: O(n)
// Memory Complexity: O(h) DFS | O(n) BFS where h = tree height
// Max distance from a given node in a tree

// DFS
ll traverseSubTree(BT *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1ll + max(traverseSubTree(root->left), traverseSubTree(root->right));
}

ll dfs(BT *root, BT *target, ll &maxDistance)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root == target)
    {
        maxDistance = max(maxDistance, traverseSubTree(root));
        return 0;
    }
    
    ll left = dfs(root->left, target, maxDistance);
    if (left != -1)
    {
        maxDistance = max(maxDistance, left + traverseSubTree(root->right));
        return left + 1;
    }

    ll right = dfs(root->right, target, maxDistance);
    if (right != -1)
    {
        maxDistance = max(maxDistance, right + traverseSubTree(root->left));
        return right + 1;
    }
    return -1;
}

ll maxDistanceFromNode(BT *root, BT *target)
{
    ll maxDistance = 0;
    dfs(root, target, maxDistance);
    return maxDistance;
}

---------------
// DFS - single dfs function. Same time complexity as the above dfs approach as each node is traversed only once in both.
ll dfs(BT *root, BT *target, ll &maxDistance, ll &height)
{
    if (root == nullptr)
    {
        height = 0;
        return -1;
    }

    ll leftHeight = 0, rightHeight = 0;

    ll leftDist = dfs(root->left, target, maxDistance, leftHeight);
    ll rightDist = dfs(root->right, target, maxDistance, rightHeight);

    height = 1 + max(leftHeight, rightHeight);

    if (root == target)
    {
        maxDistance = max(maxDistance, height - 1);
        return 0;
    }

    if (leftDist != -1)
    {
        maxDistance = max(maxDistance, leftDist + 1 + rightHeight);
        return leftDist + 1;
    }

    if (rightDist != -1)
    {
        maxDistance = max(maxDistance, rightDist + 1 + leftHeight);
        return rightDist + 1;
    }

    return -1;
}

ll maxDistanceFromNode(BT *root, BT *target)
{
    ll maxDistance = 0;
    ll height = 0;
    dfs(root, target, maxDistance, height);
    return maxDistance;
}

-------------------
// BFS - with back-edges
ll maxDistanceFromNode(BT *root, BT *target)
{
    if (!root || !target)
        return 0;

    unordered_map<BT *, BT *> parentMap;
    unordered_set<BT *> visited;
    queue<BT *> qe;

    qe.push(root);
    while (!qe.empty())
    {
        auto p = qe.front();
        qe.pop();

        if (p->left)
        {
            parentMap[p->left] = p;
            qe.push(p->left);
        }
        if (p->right)
        {
            parentMap[p->right] = p;
            qe.push(p->right);
        }
    }

    ll level = 0;
    qe.push(target);
    visited.insert(target);

    while (!qe.empty())
    {
        ll currLevelSize = qe.size();
        level++;

        while (currLevelSize--)
        {
            auto p = qe.front();
            qe.pop();

            if (parentMap.count(p) && !visited.count(parentMap[p]))
            {
                visited.insert(parentMap[p]);
                qe.push(parentMap[p]);
            }
            if (p->left && !visited.count(p->left))
            {
                visited.insert(p->left);
                qe.push(p->left);
            }
            if (p->right && !visited.count(p->right))
            {
                visited.insert(p->right);
                qe.push(p->right);
            }
        }
    }
    return level - 1;
}

------------------
Reference:
https://takeuforward.org/data-structure/minimum-time-taken-to-burn-the-binary-tree-from-a-node
