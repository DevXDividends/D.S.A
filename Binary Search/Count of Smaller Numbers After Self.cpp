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
// TC:O(n log n) SC:O(n)
class Solution {
public:
    void merge(vector<pair<int, int>>& a, int low, int mid, int high,vector<int>& ans) {
        int left = low;
        int right = mid + 1;
        vector<pair<int, int>> temp;

        while (left <= mid && right <= high) {
            if (a[left].first > a[right].first) {
                ans[a[left].second] += (high - right + 1);
                temp.push_back(a[left++]);
            } else {
                temp.push_back(a[right++]);
            }
        }

        while (left <= mid)
            temp.push_back(a[left++]);
        while (right <= high)
            temp.push_back(a[right++]);

        for (int i = low; i <= high; i++)
            a[i] = temp[i - low];
    }

    void merge_sort(vector<pair<int, int>>& a, int low, int high,vector<int>& ans) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        merge_sort(a, low, mid, ans);
        merge_sort(a, mid + 1, high, ans);
        merge(a, low, mid, high, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        merge_sort(a, 0, n - 1, ans);
        return ans;
    }
};
