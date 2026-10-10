// TC:O(M alpha(N) + K log K + N) SC:O(N + K) 
class Disjoint {
    vector<int> parent, size;

public:
    Disjoint(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mpp;
        Disjoint ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end())
                    mpp[mail] = i;
                else {
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }
        vector<string> mergedMails[n];
        for (auto it : mpp) {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMails[node].emplace_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMails[i].size() == 0)
                continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.emplace_back(accounts[i][0]);
            for (auto it : mergedMails[i])
                temp.emplace_back(it);
            ans.emplace_back(temp);
        }
        return ans;
    }
};
