// TC: O(n × 2ⁿ) SC:Auxiliary SC = O(n)
class Solution {
  public:
   void findAllSubsets(int ind,vector<int> &a,vector<int> &ds,vector<vector<int>> &ans){
       ans.emplace_back(ds);
      for(int i=ind;i<a.size();i++){
          if(i!=ind && a[i] == a[i-1])continue;
          ds.emplace_back(a[i]);
          findAllSubsets(i+1,a,ds,ans);
          ds.pop_back();
      }
       
   }
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findAllSubsets(0,arr,ds,ans);
        return ans;
    }
};
