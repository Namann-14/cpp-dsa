// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
class Solution {
  private:
    void solve(vector<int>& ans, int n, int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < n && ans[left] > ans[largest]) {
            largest = left;
        }
        if (right < n && ans[right] > ans[largest]) {
            largest = right;
        }

        if (largest != idx) {
            swap(ans[idx], ans[largest]);
            solve(ans, n, largest);
        }
    }

  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Merge both heaps
        vector<int> ans = a;
        ans.insert(ans.end(), b.begin(), b.end());

        int size = ans.size();

        // Build max-heap from combined array
        for (int i = size / 2 - 1; i >= 0; i--) {
            solve(ans, size, i);
        }

        return ans;
    }
};
