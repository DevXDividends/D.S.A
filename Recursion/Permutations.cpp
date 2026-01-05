 // TC :O(n × n!)  SC: O(n)
class Solution {
public:
    void findAllPermute(int ind,vector<int> &nums,vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.emplace_back(nums);
            return;

        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            findAllPermute(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findAllPermute(0,nums,ans);
        return ans;
    }
};
