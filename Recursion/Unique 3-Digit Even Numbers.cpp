// TC:O(n log n + n^3) SC:O(n) 
class Solution {
public:
    void f(vector<int>& a, int currDigit, vector<bool>& used, int& cnt) {
        if (currDigit > 1000)
            return;

        if (currDigit >= 100 && currDigit < 1000) {
            if (currDigit % 2 == 0) {
                cnt++;
                return;
            } else
                return;
        }
        for (int i = 0; i < a.size(); i++) {
            if (used[i])
                continue;
            if (i > 0 && a[i] == a[i - 1] && !used[i - 1])
                continue;
            if (a[i] == 0 && currDigit == 0)
                continue;
            currDigit = currDigit * 10 + a[i];
            used[i] = true;
            f(a, currDigit, used, cnt);
            currDigit = currDigit / 10;
            used[i] = false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
        int cnt = 0;
        vector<bool> used(digits.size(), false);
        f(digits, 0, used, cnt);
        return cnt;
    }
};
