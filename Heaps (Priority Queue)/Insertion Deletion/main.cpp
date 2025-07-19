#include <bits/stdc++.h>
using namespace std;

class Heap {
    private:
        vector<int> nums;

        void heapifyUp(int idx) {
            if (idx == 0) return;
            int parent = (idx - 1) / 2;
            if (nums[idx] > nums[parent]) {
                swap(nums[idx], nums[parent]);
                heapifyUp(parent);
            }
        }

        void heapifyDown(int idx) {
            int largest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < nums.size() && nums[left] > nums[largest]) {
                largest = left;
            }

            if (right < nums.size() && nums[right] > nums[largest]) {
                largest = right;
            }

            if (largest != idx) {
                swap(nums[idx], nums[largest]);
                heapifyDown(largest);
            }
        }

    public: 
        Heap() {
            nums.clear();
        }

        void insert(int val) {
            nums.push_back(val);
            heapifyUp(nums.size() - 1);
        }

        int deleteMax() {
            if (isEmpty()) {
                cout << "Heap is empty! Cannot delete." << endl;
                return -1;
            }

            int maxVal = nums[0];
            
            if (nums.size() == 1) {
                nums.pop_back();
                return maxVal;
            }

            nums[0] = nums.back();
            nums.pop_back();
            heapifyDown(0);
            
            return maxVal;
        }

        void display() {
            if (isEmpty()) {
                cout << "Heap is empty!" << endl;
                return;
            }
            cout << "Heap: ";
            for (int i = 0; i < nums.size(); i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }

        int getSize() {
            return nums.size();
        }

        bool isEmpty() {
            return nums.empty();
        }

        int getMax() {
            if (!isEmpty()) {
                return nums[0];
            } else {
                cout << "Heap is empty!" << endl;
                return -1;
            }
        }
};


int main() {
    Heap heap;
    int choice;
    
    do {
        cout << "\n=== HEAP OPERATIONS ===" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete maximum element" << endl;
        cout << "3. Display heap" << endl;
        cout << "4. Get maximum element" << endl;
        cout << "5. Get heap size" << endl;
        cout << "6. Check if empty" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                cout << "After inserting " << value << ": ";
                heap.display();
                break;
            }
            case 2: {
                int deleted = heap.deleteMax();
                if (deleted != -1) {
                    cout << "Deleted maximum element: " << deleted << endl;
                    cout << "Heap after deletion: ";
                    heap.display();
                }
                break;
            }
            case 3: {
                heap.display();
                break;
            }
            case 4: {
                int max = heap.getMax();
                if (max != -1) {
                    cout << "Maximum element: " << max << endl;
                }
                break;
            }
            case 5: {
                cout << "Heap size: " << heap.getSize() << endl;
                break;
            }
            case 6: {
                cout << "Heap is " << (heap.isEmpty() ? "empty" : "not empty") << endl;
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    } while (choice != 0);
    
    return 0;
}