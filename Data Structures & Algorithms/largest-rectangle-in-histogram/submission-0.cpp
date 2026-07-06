class Solution {
public:

    vector<int> previousSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                prev[i] = -1;
            } else {
                prev[i] = st.top();
            }

            st.push(i);
        }

        return prev;
    }

    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                next[i] = n;
            } else {
                next[i] = st.top();
            }

            st.push(i);
        }

        return next;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> prev = previousSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            int area = height * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};