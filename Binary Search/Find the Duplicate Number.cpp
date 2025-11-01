// brute force TC:o(n) SC:O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int n : nums)
            mpp[n]++;
        for (int i = 0; i < n; i++) 
            if (mpp[nums[i]] > 1)
                return nums[i];
        
        return -1;
    }
};
// better TC:O(n^2) SC:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (j != i && nums[i] == nums[j])
                    return nums[i];

        return -1;
    }
};
// more better TC:O(n log n + O(n) SC:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid+1<=n && nums[mid]==nums[mid+1]) return nums[mid];
            if(mid<nums[mid])low=mid+1;
            else high=mid-1;
        }
        return -1;


    }
};
// optimal TC:O(n) SC:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];

        }while(slow!=fast);
        fast = nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
