class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int num:nums){
            numSet.insert(num);
        }
        int longest=0;
        for(int num:numSet){
            if(numSet.find(num-1)==numSet.end()){
                int currentNum=num;
                int currentLength=1;
                while(numSet.find(currentNum+1)!=numSet.end()){
                    currentNum++;
                    currentLength++;
                }
                longest=max(longest,currentLength);
            }
        }
        return longest;
    }
};
