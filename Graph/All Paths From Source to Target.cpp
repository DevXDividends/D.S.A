/* Time:  O(P × L)
Space: O(P × L)   // including output
       O(n)       // auxiliary recursion/path space
*/
class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int> currPath,
             vector<vector<int>>& paths, int& terminalNode) {
        currPath.emplace_back(node);

        if (node == terminalNode) {
            paths.emplace_back(currPath);
            return;
        }
        for (auto n : graph[node]) {
            dfs(n, graph, currPath, paths, terminalNode);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> paths;
        vector<int> currPath;
        int terminalNode = graph.size() - 1;
        dfs(0, graph, currPath, paths, terminalNode);
        return paths;
    }
};
