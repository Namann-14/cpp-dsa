// https://www.geeksforgeeks.org/problems/heap-sort/1
class Solution {
  private:
    void solve(vector<int>& nums, int n, int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != idx) {
            swap(nums[largest], nums[idx]);
            solve(nums, n, largest);
        }
    }
    void heap_sort(vector<int>& nums, int n) {
        int temp = n - 1;
        while (temp) {
            swap(nums[temp], nums[0]);
            solve(nums, temp, 0);
            temp--;
        }
    }
  public:
    void heapSort(vector<int>& nums) {
        // step 1: array ka heap banao
        int n = nums.size();
        for (int i = n/2 - 1; i >= 0; i--) {
            solve(nums, n, i);
        }
        
        // step 2: heap ko sort kardo
        heap_sort(nums, n);
    }
};