// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
class Solution {
  private:
    int calc(Node* root) {
        if (!root) return 0;
        return 1 + calc(root->left) + calc(root->right);
    }

    bool isCBT(Node* root, int idx, int count) {
        if (!root) return true;
        if (idx >= count) return false;
        return isCBT(root->left, 2 * idx + 1, count) &&
               isCBT(root->right, 2 * idx + 2, count);
    }

    bool isMaxi(Node* root) {
        if (!root->left && !root->right) return true;

        if (root->left && !root->right)
            return (root->data >= root->left->data) && isMaxi(root->left);

        if (root->left && root->right)
            return (root->data >= root->left->data) &&
                   (root->data >= root->right->data) &&
                   isMaxi(root->left) &&
                   isMaxi(root->right);

        return false;
    }

  public:
    bool isHeap(Node* root) {
        int count = calc(root);
        return isCBT(root, 0, count) && isMaxi(root);
    }
};
