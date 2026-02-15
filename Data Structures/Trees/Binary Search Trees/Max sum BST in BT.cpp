// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Maximum sum BST sub tree in a BT

class Result
{
  public:
    bool isValidBST;
    ll minNode;
    ll maxNode;
    ll sum;

    Result()
    {
        isValidBST = true;
        minNode = LLONG_MAX;
        maxNode = LLONG_MIN;
        sum = 0;
    }

    Result(bool isValidBST, ll minNode, ll maxNode, ll sum)
    {
        this->isValidBST = isValidBST;
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

Result postOrder(BT *root, ll &maxSum)
{
    if (!root)
    {
        return Result();
    }

    Result leftSubTree = postOrder(root->left, maxSum);
    Result rightSubTree = postOrder(root->right, maxSum);

    if (leftSubTree.isValidBST && rightSubTree.isValidBST && leftSubTree.maxNode < root->val &&
        rightSubTree.minNode > root->val)
    {
        maxSum = max(maxSum, leftSubTree.sum + root->val + rightSubTree.sum);
        return Result(true, (leftSubTree.minNode != LLONG_MAX ? leftSubTree.minNode : root->val),
                      (rightSubTree.maxNode != LLONG_MIN ? rightSubTree.maxNode : root->val),
                      leftSubTree.sum + root->val + rightSubTree.sum);
    }
    else
    {
        return Result(false, 0, 0, 0);
    }
}

ll maxSumBST(BT *root)
{
    ll maxSum = 0;
    postOrder(root, maxSum);
    return maxSum;
}
