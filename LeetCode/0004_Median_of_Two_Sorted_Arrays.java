class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double median = 0.0;
        ArrayList<Integer> concated = new ArrayList<>();
        int idx1 = 0;
        int idx2 = 0;
        
        while (idx1 < nums1.length && idx2 < nums2.length) {
            if (nums1[idx1] <= nums2[idx2]) {
                concated.add(nums1[idx1++]);
            }
            else {
                concated.add(nums2[idx2++]);
            }
        }
        
        if (idx1 == nums1.length) {
            while (idx2 < nums2.length) {
                concated.add(nums2[idx2++]);
            }
        }
        else if (idx2 == nums2.length) {
            while (idx1 < nums1.length) {
                concated.add(nums1[idx1++]);
            }
        }
        
        idx1 = concated.size() / 2;
        if (concated.size() == 0) {
                median = 0.0;
            }
        else if (concated.size() == 1) {
                median = concated.get(0);
        }
        else if (concated.size() % 2 == 0) {
            idx2 = idx1 - 1;
            median = ((concated.get(idx1)) + concated.get(idx2)) / 2.0;
        }
        else {
            median = concated.get(idx1);
        }
        
        return median;
    }
}
