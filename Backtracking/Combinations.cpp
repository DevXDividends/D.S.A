class Solution {
public:
    void solve(int num,int &n, int& k, vector<int>& ds, vector<vector<int>>& ans) {
        if (ds.size() == k) {
            ans.emplace_back(ds);
            return;
        }
        for (int i = num; i <= n; i++) {
            ds.emplace_back(i);
            solve(i + 1,n, k, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        vector<int> ds;
        vector<vector<int>> ans;
        solve(1, n,k, ds, ans);
        return ans;
    }
};
