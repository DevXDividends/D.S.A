// brute force TC:O(n * m) SC:O(1)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, k;
    int cnt = 0;
    cin >> n >> m >> k;
    unordered_map<int, int> mpp;
    vector<int> applicants;
    vector<int> apartments;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        applicants.emplace_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        apartments.emplace_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (apartments[j] >= applicants[i] - k && apartments[j] <= applicants[i] + k)
            {

                if (mpp.count(j))
                    continue;
                cnt++;
                mpp[j] = 1;
                break;
            }
        }
    }
    cout << cnt;
}
// TC:O(n log n + m log m) SC:O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &applicants, vector<int> &apartments, int k)
{
    sort(applicants.begin(),applicants.end());
    sort(apartments.begin(),apartments.end());
    int i = 0, j = 0, ans = 0;
    while (i < applicants.size() && j < apartments.size())
    {
        if (abs(applicants[i] - apartments[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if (applicants[i] - apartments[j] > k)
            j++;
        else
            i++;
    }
    return ans;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants;
    vector<int> apartments;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        applicants.emplace_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        apartments.emplace_back(x);
    }
    cout << find(applicants, apartments, k);
}
