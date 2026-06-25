// brute TC:O(n^2) SC:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=target)
                minLength = min(minLength,j-i+1);
            }
        }
        return minLength==INT_MAX?0:minLength;
    }
};
// optimal TC:O(n) SC:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0;
       int l = 0,r = 0;
       while(r<n){
        sum+=nums[r];
        while(sum>=target){
            minLength = min(minLength,r-l+1);
            sum-=nums[l++];
        }
        r++;
       }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
