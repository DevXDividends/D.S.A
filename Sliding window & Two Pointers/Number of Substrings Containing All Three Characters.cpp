// brute force TC:O(n^2) SC:O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> hash(3, 0);
            for (int j = i; j < n; j++) {
                hash[s[j] - 'a'] = 1;
                if (hash[0] + hash[1] + hash[2] == 3)
                    cnt++;
            }
        }
        return cnt;
    }
};
// optimal TC:O(n) SC:O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastSeen(3, -1);
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
            cnt += (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
        return cnt;
    }
};
