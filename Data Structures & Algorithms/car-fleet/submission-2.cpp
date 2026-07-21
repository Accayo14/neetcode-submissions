class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();

        for(int i = 0; i < n; i++){
            cars.push_back({target - position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        vector<float> time(n);
        for(int i = 0; i < n; i++){
            time[i] = (float)cars[i].first / (float)cars[i].second;
        }

        int fleet = 1;
        float tmin = time[0];
        for(int i = 1; i < n; i++){
            if(time[i] <= tmin) continue;
            else{
                fleet++;
                tmin = time[i];
            }
        }

        return fleet;
    }
};
