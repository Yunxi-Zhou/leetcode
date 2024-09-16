#include <stdio.h>
#include <stdlib.h>
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

// the actual time complexity should be O((m + n) log (m + n))
//function declaration
int compare(const void* a, const void* b);
double findMedianSortedArray(int* nums1, int nums1Size, int* nums2, int nums2Size);
//main function
int main() {
    int nums1[] = {1,2};
    int nums2[] = {3,4};
    double result = findMedianSortedArray(nums1,sizeof(nums1)/sizeof(nums1[0]), nums2, sizeof(nums2)/sizeof(nums2[0]));
    printf("%f\n", result);
    return 0;
}


//function definition
int compare(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

double findMedianSortedArray(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int* combine = (int*)malloc(totalSize * sizeof(int));

    //combine two arrays together
    for (int i = 0; i < nums1Size; i++) {
        combine[i] = nums1[i];
    }
    for (int j = 0; j < nums2Size; j++) {
        combine[nums1Size + j] = nums2[j];
    }

    //sort the arrays
    qsort(combine, totalSize, sizeof(int),compare);

    // find median 
    double median = 0.0;
    if (totalSize % 2 == 1) {
        median = combine[totalSize / 2];
    } else {
        median = (combine[totalSize / 2 - 1] + combine[totalSize/2])/2.0;
    }

    free(combine);
    return median;
}