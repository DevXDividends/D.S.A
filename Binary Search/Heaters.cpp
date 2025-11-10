// TC:O(n × log m) SC:So = O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int maxDist=0;
        for(int house:houses){
            auto it=lower_bound(heaters.begin(),heaters.end(),house);
            int dist=INT_MAX;
            if(it!=heaters.end())dist=min(dist,abs(*it-house));
            if(it!=heaters.begin()){
                it--;
                dist=min(dist,abs(*it-house));
            }
            maxDist=max(maxDist,dist);

        }
        return maxDist;
    }
};
