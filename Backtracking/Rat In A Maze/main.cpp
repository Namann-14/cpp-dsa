// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution {
  private:
    bool isSafe(int x, int y, vector<vector<int>>& maze, int n, vector<vector<bool>>& vis) {
        if ((x >= 0 && x <= n - 1) && ((y >= 0 && y <= n - 1)) && maze[x][y] == 1 && vis[x][y] == false) {
            return true;
        }
        return false;
    }
    void solve(int x, int y, vector<vector<int>>& maze, vector<string>& ans, int n, vector<vector<bool>>& vis, string path){
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
        // D L R U
        vis[x][y] = true;
        
        // Down
        if (isSafe(x + 1, y, maze, n, vis))
            solve(x + 1, y, maze, ans, n, vis, path + 'D');

        // Left
        if (isSafe(x, y - 1, maze, n, vis))
            solve(x, y - 1, maze, ans, n, vis, path + 'L');

        // Right
        if (isSafe(x, y + 1, maze, n, vis))
            solve(x, y + 1, maze, ans, n, vis, path + 'R');

        // Up
        if (isSafe(x - 1, y, maze, n, vis))
            solve(x - 1, y, maze, ans, n, vis, path + 'U');
        
        vis[x][y] = false;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string>ans;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        string path = "";
        if (maze[0][0] == 0) {
            return ans;
        }
        solve(0, 0, maze, ans, n, vis, path);
        return ans;
    }
};