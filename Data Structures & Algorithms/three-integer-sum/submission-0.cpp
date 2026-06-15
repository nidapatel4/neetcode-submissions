class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int left=i+1;
            int right=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(left<right){
                if(nums[left]+nums[right]< -nums[i]){
                    left++;
                }
                else if(nums[left]+nums[right]> -nums[i]){
                    right--;
                }
                else{
                      result.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                left++;
            }
            while(left<right && nums[right]==nums[right-1]){
                right--;
            }
            left++;
            right--;
                  
                }
            }
        }
        return result;
    }
};
