/*4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizein = nums1.size()+nums2.size();
        int a[sizein];
        int i,j;
        for(i=1;i<nums1.size()+1;i++)
            a[i-1] = nums1[i-1];
        int size = nums1.size();
        for(i=1;i<nums2.size()+1;i++){
            a[size] = nums2[i-1];
            size++;
        }
        size = nums1.size()+nums2.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;  
                }
            }
}

        int med;
        double k;
        if(sizeof(a)/ sizeof(a[0])==0){
            return {};
        }
        else if(sizeof(a)/ sizeof(a[0])==1){
            med = a[0];
            return med;
        }
        else{
            med = (size)/2;
            k = (size)/2;
        }
        double out;
        int b;
        for(i=0;i<med;i++)
             b = a[i];
        if ( sizein % 2== 0){
            out = b + a[med];
            out = out / 2;
            return out;
        }
        return a[med];
    }
};