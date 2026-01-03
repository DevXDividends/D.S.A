// TC = O(2ⁿ *  n) O(n)
class Solution {
public:
   void findAllSubsets(int ind, vector<int>& a,vector<int>& ds,vector <vector<int>> &ans) {
        if (ind == a.size()) {
            ans.emplace_back(ds);
            return;
        }
        // take
        ds.emplace_back(a[ind]);
        findAllSubsets(ind + 1, a, ds, ans);

        // not take
        ds.pop_back();
        findAllSubsets(ind + 1, a, ds, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findAllSubsets(0, nums, ds, ans);
        return ans;
    }
};
