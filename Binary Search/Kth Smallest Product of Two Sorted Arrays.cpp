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
