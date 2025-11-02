// TC:O(n^2) SC:O(1)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j]) ==k)cnt++;
            }
        }
        return cnt;

    }
};
// TC:O(n) SC:O(n)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int cnt = 0;
        for (int n : nums) {
           cnt+=mpp[n-k];
           cnt+=mpp[n+k];
           mpp[n]++;
        }
        return cnt;
    }
};
