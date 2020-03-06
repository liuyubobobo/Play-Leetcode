/**
 * @author: qiaoyi
 * @edit:
 * @created:2019/09/10
 * Time Complexity:O(n)
 * Space Complexity:O(1)
 */
public class Solution2 {

    //do not use auxilliary array, tranverse num1 from back to front
    public static void merge2(int[] nums1, int m, int[] nums2, int n) {
        if (n <= 0) {
            return;
        }
        int point1 = m - 1;
        int point2 = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {

            if (point1 >= 0 && point2 >= 0 && nums1[point1] > nums2[point2]) {
                nums1[i] = nums1[point1];
                point1--;
            } else if (point2 >= 0) {
                nums1[i] = nums2[point2];
                point2--;
            } else {
                nums1[i] = nums1[point1];
                point1--;
            }
        }
    }

    public static void main(String[] args) {
        int[] num1 = {1, 2, 3, 0, 0, 0};
        int[] num2 = {2, 5, 6};
        merge(num1, 0, num2, 1);
    }
}
