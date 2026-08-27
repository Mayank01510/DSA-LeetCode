class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time = 0;
        int prev = 0;
        for(auto it : requests){
            time += abs(prev - it);
            prev = it;
        }
        return time;
    }
};