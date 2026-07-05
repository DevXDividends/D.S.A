// brute force TC:O(n^2) SC:O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += nums[j];
                if (currSum == goal)
                    cnt++;
            }
        }
        return cnt;
    }
};
// optimal TC:O(n) SC:O(1)
class Solution {
public:
    int slidingWindow(vector<int>& nums, int goal,int &n) {
        if (goal < 0)
            return 0;
       
        int cnt = 0;
        int l = 0, r = 0;
        int sum = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > goal)
                sum -= nums[l++];
            if (sum <= goal)
                cnt += (r - l) + 1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int n = nums.size();
        return slidingWindow(nums, goal,n) - slidingWindow(nums, goal - 1,n);
    }
};

/*
imaging the goal =2 
the first funciton call will finds subarrays which will include 0 , 1 , 2
the 2nd funciton call will find subarrays with goal =1 (goal - 1 ) = 0 , 1 
subtracting both of them will give us subarrays with goal exacrly = 2
(0 , 1 , 2 ) - (0 , 1 ) = 2 !
*/
