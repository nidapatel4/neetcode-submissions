class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size());
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
                if(st.empty()){
                    result[i]=0;
                }
                else{
                    result[i]=st.top()-i;
                }
                st.push(i);
            
        }
        return result;
    }
};
