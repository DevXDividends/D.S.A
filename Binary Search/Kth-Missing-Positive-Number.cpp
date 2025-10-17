// Brute force approach TC: O(n)  SC:O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        for (int n : arr) {
            if (n <= k)
                k++;
            else
                return k;
        }
        return k;
    }
};

// optimal approach using binary search TC:(log n) SC:O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k; // or return k+high+1;
    }
};

Consider this array : [2,3,4,7,11]
    here according to the indexes the numbers as per the indexes are 1,2,3,4,5 ......size of array is 5 
    so to find the no missing number at an index  we do : arr[ind] - indd+1; 
    Eg : if i am standing at 1st indedx then the no of missin no would be   2 - 1 = 1
    same for 2th index :3 - 2 = 1;
    ........ 3rd index : 4 - 3 = 1  
        at index 4th : 7 - 4 = 3;
           index 5th : 11 - 5 = 6 


if k = 5 then i know my number lies between the missing index (3,6);
so i ll apply binary search to find this indexes

Consider the array:
arr = [2, 3, 4, 7, 11]

We want to find the 5th missing number (k = 5).
Step 1️⃣ — Understanding Missing Count at Each Index
We compute missing numbers till each index using:

missing = arr[mid] - (mid+1)
missing=arr[i]−(i+1)
Index (0-based)	arr[i]	Expected	Missing Count (arr[i] - (i+1))
0	2	1	1
1	3	2	1
2	4	3	1
3	7	4	3
4	11	5	6
Step 2️⃣ — Locate the Range for the k-th Missing Number
We’re looking for where missing crosses or equals k.
At index 3, missing = 3 (< 5)
At index 4, missing = 6 (> 5)
So, the 5th missing number lies between indexes 3 and 4,
i.e., between arr[3] = 7 and arr[4] = 11.

Step 3️⃣ — Apply Binary Search

Binary search helps us quickly find the first index where
missing >= k.
after binary search 
At the end of the loop:
low points to the first index where missing ≥ k
Formula → answer = low + k
low = 4
k = 5
ans = low + k = 4 + 5 = 9



