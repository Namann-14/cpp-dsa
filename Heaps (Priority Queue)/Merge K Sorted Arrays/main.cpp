// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
class Node {
    public: 
        int val;
        int row;
        int col;
        Node(int val, int row, int col) {
            this -> val = val;
            this -> row = row;
            this -> col = col;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    auto cmp = [](Node* a, Node* b) {
        return a -> val > b -> val;
    };
    priority_queue<Node*, vector<Node*>, decltype(cmp)>pq(cmp);
    for (int i = 0; i < kArrays.size(); i++) {
        pq.push(new Node(kArrays[i][0], i, 0));
    }
    vector<int>ans;
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        ans.push_back(x -> val);
        if (x -> col + 1< kArrays[x -> row].size()) {
            pq.push(new Node(kArrays[x -> row][x -> col + 1], x -> row, x -> col + 1));
        }
    }
    return ans;

}
