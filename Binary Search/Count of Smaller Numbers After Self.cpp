// brute force TC:O(n^2) SC:O(n)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>counts;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i])cnt++;
            }
            counts.emplace_back(cnt);
        }
        return counts;
    }
};
