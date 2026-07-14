class Solution {
public:
void solve(int ind,vector<int> &a,int currXOR,int &ans){
    if(ind==a.size()){
        ans+=currXOR;
        return;
    }
    solve(ind+1,a,currXOR,ans);
    currXOR^=a[ind];
    solve(ind+1,a,currXOR,ans);
    currXOR^=a[ind];
}
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        solve(0,nums,0,ans);
        return  ans;
    }
};