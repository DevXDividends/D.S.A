// TC:O(2^N) SC:O(N)
class Solution {
public:
    vector<vector<int>> findCombinations(int ind, int target, vector<int>& arr,
                                         vector<int>& ds,
                                         vector<vector<int>>& ans) {
        if (target == 0) {
            ans.emplace_back(ds);
            return ans;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            // pick
            ds.emplace_back(arr[i]);
            findCombinations(i + 1, target - arr[i], arr, ds, ans);
            // remove the picked one
            ds.pop_back();
        }
        return ans;

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ds, ans);
        return ans;
    }
};
