class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //always work on the smaller array
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0;
        int high=n1;

        while(low<=high){
            //partition of nums1
            int partition1=low+(high-low)/2;
            //partition of nums2
            int partition2=((n1+n2+1)/2)-partition1;
             int l1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int r1 = (partition1 == n1) ? INT_MAX : nums1[partition1];

            int l2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int r2 = (partition2 == n2) ? INT_MAX : nums2[partition2];

            // Correct partition found
            if (l1 <= r2 && l2 <= r1) {

                // Odd total elements
                if ((n1 + n2) % 2 == 1) {
                    return max(l1, l2);
                }

                // Even total elements
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // Move partition1 to the left
            else if (l1 > r2) {
                high = partition1 - 1;
            }

            // Move partition1 to the right
            else {
                low = partition1 + 1;
            }
        }

        return 0.0;
        }
    };
