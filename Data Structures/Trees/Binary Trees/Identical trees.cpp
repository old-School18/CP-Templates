// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Check if two trees are identical by skeleton and node values

bool areIdenticalTrees(BT *p, BT *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr || p->data != q->data)
    {
        return false;
    }

    return areIdenticalTrees(p->left, q->left) && areIdenticalTrees(p->right, q->right);
}
