#include <iostream>

/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

int maxSubArray(int* nums, int numsSize){
    // assert nums and numSize > 0

    int *numsSentinel = nums + numsSize;
    int *numsPtr = nums;
    
    int *leftPtr = nums;
    int *rightPtr = numsSentinel;

    int *maxLeftPtr = leftPtr;

    int maxSum = INT32_MIN;
    int thisSum = 0;

    // find the biggest starting point
    int maxSum2 = INT32_MIN;
    while (leftPtr < rightPtr) {
        thisSum = 0;
        numsPtr = leftPtr;
        while (numsPtr < rightPtr) {
            thisSum += *numsPtr;
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
            numsPtr++;
        }
        if (maxSum > maxSum2) {
            maxSum2 = maxSum;
            maxLeftPtr = leftPtr;
        }
        leftPtr++;
    }

    leftPtr = maxLeftPtr;
    maxSum = INT32_MIN;

    // find biggest right side
    while (rightPtr > leftPtr) {
        // find the biggest left
        thisSum = 0;
        numsPtr = leftPtr;
        while (numsPtr < rightPtr) {
            thisSum += *numsPtr;
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
            numsPtr++;
        }
        rightPtr--;
    }

    return maxSum;
}

int leet2_test() {
    int foo[] = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << "{-2,1,-3,4,-1,2,1,-5,4}=" << maxSubArray(foo, sizeof(foo) / sizeof(foo[0])) << std::endl;

    int foo2[] = {-2,-1};
    std::cout << "{-2,-1}=" << maxSubArray(foo2, sizeof(foo2) / sizeof(foo2[0])) << std::endl;

    int foo3[] = {1,2};
    std::cout << "{1,2}=" << maxSubArray(foo3, sizeof(foo3) / sizeof(foo3[0])) << std::endl;

    return 0;
}
