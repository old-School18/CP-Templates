// Time Complexity: O(n)
// Memory Complexity: O(1)
// Convert binary tree to single linked list in pre order where the left node is null and right node points to the next node in the linked list


// Morris traversal approach
void flatten(TreeNode *root)
{
    while (root != nullptr)
    {
        if (root->left != nullptr)
        {
            BT *prev = root->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
    return;
}
