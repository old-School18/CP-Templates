// Time Complexity: O(n)
// Memory Complexity: O(h)
// Two nodes whose values sum to a given number

class BSTIterator
{
  private:
    stack<BST *> st;
    bool reverse;

    void pushAll(BST *node)
    {
        while (node)
        {
            st.push(node);
            if (!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }

  public:
    BSTIterator(BST *root, bool reverse)
    {
        this->reverse = reverse;
        pushAll(root);
    }

    bool hasNext()
    {
        return !st.empty();
    }

    ll next()
    {
        if (!hasNext())
            return -1;
        BST *node = st.top();
        st.pop();

        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);

        return node->val;
    }
};

bool twoSum(BST *root, ll k)
{
    BSTIterator leftptr(root, false), rightptr(root, true);
    ll left = leftptr.next(), right = rightptr.next();
    while (left < right)
    {
        if (left + right < k)
        {
            left = leftptr.next();
        }
        else if (left + right == k)
        {
            return true;
        }
        else
        {
            right = rightptr.next();
        }
    }
    return false;
}
