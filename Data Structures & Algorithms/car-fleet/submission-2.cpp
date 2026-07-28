class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        }
        int fleet=0;
        double lasttime=0;
        for(auto &car:cars){
            double time=double(target-car.first)/car.second;
            if(time>lasttime){
                fleet++;
                lasttime=time;
            }
        }
        return fleet;
    }
};
