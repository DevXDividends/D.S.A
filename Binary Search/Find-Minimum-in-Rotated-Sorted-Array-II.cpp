// Brute approach : TC:O(n) SC:O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        for(int n:nums){
            if(n<min) min=  n;
        }
        return min;
    }
};

// optimal approach TC:O(log n) SC:O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            if(nums[mid] > nums[high]) low=mid+1;
            else if(nums[mid]<nums[high]) high=mid;
            else high--;
        }
        return nums[low];
    }
};
