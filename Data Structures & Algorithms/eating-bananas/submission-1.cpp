class Solution {
public:
    int calculateHours(vector<int>& piles,int speed){
    int hours=0;
    for(int pile:piles){
        int hoursNeeded=(pile+speed-1)/speed;
        hours+=hoursNeeded;
    }
    return hours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
    int low=1;
    int high=*max_element(piles.begin(),piles.end());
    int ans=high;
    while(low<=high){
        int mid = low + (high - low) / 2;
        int totalHours = calculateHours(piles, mid);

    if(totalHours<=h){
    ans=mid;
    high=mid-1;
    }
    else {
        low=mid+1;
    }
    }
    return ans;
    }
};
