class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        for(int i=0;i<position.size();i++){
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end());

        double fleetTime=0;
        int fleetCount=0;
        
        for(int i=cars.size()-1;i>=0;i--){
            // instead of doing cars[i].second everytime 
            double currentTime=cars[i].second;
            if(currentTime > fleetTime){
                fleetTime=currentTime;
                fleetCount++;
            }
            // else{
            //     fleetTime;
            // } this is unnecesaryyy
        }
        return fleetCount;
    }
};
