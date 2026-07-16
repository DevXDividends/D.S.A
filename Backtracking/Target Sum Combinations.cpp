class Solution {
  public:
    void solve(int ind,vector<int> &a,int currSum,vector<int> &ds,vector<vector<int>> &ans,int &target){
        if(currSum>target)
        return;
        if(currSum==target){
            ans.emplace_back(ds);
            return;
        }
        for(int i=ind;i<a.size();i++){
            ds.emplace_back(a[i]);
            currSum+=a[i];
            solve(i,a,currSum,ds,ans,target);
            ds.pop_back();
            currSum-=a[i];
        }
    }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,arr,0,ds,ans,target);
        return ans;
    }
};
