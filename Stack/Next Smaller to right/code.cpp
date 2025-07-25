#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int>nextSmaller(vector<int>& nums, int n, stack<int>& s){
    s.push(-1);
    vector<int>ans(n);
    for (int i = n - 1; i >= 0; i--){
        int curr = nums[i];
        while (s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>nums;
    for (int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }
    stack<int>s;
    vector<int>ans = nextSmaller(nums, n, s);

    for (int i = 0; i < n; i++) cout << ans[i]<< " ";

    return 0;
}