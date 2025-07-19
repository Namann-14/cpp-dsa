#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>nextGreater(vector<int>& nums, int n, stack<int>& s){
    vector<int>ans(n);
    for (int i = 0; i < n; i++){
        int curr = nums[i];
        while (!s.empty() && s.top() <= curr){
            s.pop();
        }
        ans[i] = (s.empty()) ? -1 : s.top();
        s.push(nums[i]);
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
    vector<int>ans = nextGreater(nums, n, s);

    for (int i = 0; i < n; i++) cout << ans[i]<< " ";
    return 0;
}