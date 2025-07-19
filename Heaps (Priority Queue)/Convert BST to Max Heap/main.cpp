// https://www.geeksforgeeks.org/problems/bst-to-max-heap/1
class Solution {
  private:
    void in(Node* root, vector<int>& nums) {
        if (!root) return;
        in(root -> left, nums);
        nums.push_back(root -> data);
        in(root -> right, nums);
    }
    void solve(Node* root, int& idx, vector<int>& nums) {
        if (!root || idx < 0) return;
        root -> data = nums[idx--];
        solve(root -> right, idx, nums);
        solve(root -> left, idx, nums);
    }
  public:
    void convertToMaxHeapUtil(Node* root) {
        vector<int>nums;
        in(root, nums);
        int idx = nums.size() -1;
        solve(root, idx, nums);
    }
};
