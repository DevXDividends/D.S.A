// brute force TC:O(n^2) SC:O(3) or O(1)
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> stt;
            for (int j = i; j < n; j++) {
                if (stt.find(s[j]) != stt.end() || stt.size()>3)
                    break;
                else
                    stt.insert(s[j]);
                if (stt.size() == 3){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
