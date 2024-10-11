class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        sum = 0
        median = 0
        length = len(nums1)+len(nums2)
        newlis = (nums1+nums2)
        newlis.sort()
        if(length %2 !=0):
            median = newlis[length//2]
        else:
            a = newlis[length//2]+newlis[(length//2)-1]
            median = a/2
        print(newlis)
        return float(median)