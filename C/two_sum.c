/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 20000
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int *)malloc(2 * sizeof(int));
    int* hashMap = (int *)malloc(HASH_SIZE * sizeof(int));

    for (int i = 0; i < HASH_SIZE; i++) {
        hashMap[i] = -1;
        // hashMap[1,2,3,4,...,HASH_SIZE] = [-1,-1,-1,-1,-1...]
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = (complement%HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        // used to calculate a valid non-negative number into a hash table

        if (hashMap[index] != -1) {
            res[0] = i;
            res[1] = hashMap[index];
            *returnSize = 2;
            free(hashMap);
            hashMap = NULL;
            return res;
        }

        index = (nums[i]%HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        hashMap[index] = i;

    }
    free(hashMap);
    return NULL;
}

int main() {
    int nums[3] = {3,2,4};
    int returnSize = 0;

    int* result = twoSum(nums,3,6,&returnSize);

    if (result != NULL) {
        for (int i = 0; i < returnSize; i++) {
            printf("%d\n", result[i]);
        }  
    } else {
        printf("No solution found\n");
    }

    free(result);
    result = NULL;
    return 0;

}