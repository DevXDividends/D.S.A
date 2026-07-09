// TC:O(2^n) SC:O(n * 2^n)
class Solution {
  public:
  void solve(int ind,string &s,string &currStr,vector<string> &ans){
      if(ind==s.size()){
          ans.emplace_back(currStr);
          return ;
      }
      // not take
      solve(ind+1,s,currStr,ans);
      
      //take
      currStr+=s[ind];
      solve(ind+1,s,currStr,ans);
      
      // pop back the string
      currStr.pop_back();
  }
    vector<string> powerSet(string &s) {
        vector<string> ans;
        string currStr;
        solve(0,s,currStr,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
