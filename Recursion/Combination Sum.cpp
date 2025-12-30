// TC : O(2^t *  k) SC :O(t)
class Solution {
public:
    void findCombination(int ind, int target, vector<int> arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        // base case
        if (ind == arr.size()) {
            if (!target) {
                ans.emplace_back(ds);
            }
            return;
        }
        // take 
        if(arr[ind]<=target){
            ds.emplace_back(arr[ind]);
            findCombination(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findCombination(++ind,target,arr,ans,ds);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
