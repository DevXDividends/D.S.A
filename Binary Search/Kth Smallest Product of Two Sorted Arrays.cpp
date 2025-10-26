 // brute force approach TC:O(n1 × n2 log(n1 × n2)) SC:O(nums1 * nums2)
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<long long> products;
        for(int a:nums1){
            for(int b:nums2){
                products.emplace_back(1ll * a * b);
            }
        }
        sort(products.begin(),products.end());
        return products[k-1];
    }
};
// optimalTC:O(n1⋅logn2⋅log(max_product - min_product))  SC:O(1)
class Solution {
public:
    long long checkLess(const vector<int>& a, const vector<int>& b,long long mid) {
        long long cnt = 0;
        int n = b.size();
        for (int x : a) {
            if (x > 0) {
                long long target = (long long)floor((double)mid / x);

                cnt += upper_bound(b.begin(), b.end(), target) - b.begin();

            } else if (x < 0) {
                cnt += b.end() - lower_bound(b.begin(), b.end(),
                                             (long long)ceil((double)mid / x));
            } else {
                if (mid >= 0)
                    cnt += n;
            }
        }
        return cnt;
    }
    long long kthSmallestProduct(vector<int>& a, vector<int>& b, long long k) {
        long long low = min({1LL * a[0] * b[0], 1LL * a[0] * b.back(),
                             1LL * a.back() * b[0], 1LL * a.back() * b.back()});
        long long high =
            max({1LL * a[0] * b[0], 1LL * a[0] * b.back(),
                 1LL * a.back() * b[0], 1LL * a.back() * b.back()});

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (checkLess(a, b, mid) >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
