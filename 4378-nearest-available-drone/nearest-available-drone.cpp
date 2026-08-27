class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int d = INT_MAX;
        int ind = 0;
        for(int i= 0;i<drones.size();i++){
            auto it  = drones[i];
            int dis  = abs(it[0] - target[0]) + abs(it[1] - target[1]);
            if(dis <= it[2] && dis < d){
                ind = i;
                d = dis;
            }
        }
        if(d != INT_MAX)return ind;
        return -1;
    }
};