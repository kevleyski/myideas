#include <iostream>

/* OPTIMIZATION
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */

int singleNumber2 (int *nums, int numsSize)
{
    // assert nums and numSize > 0

    int *numsSentinel = nums + numsSize;
    int *numsPtr = nums;
    int singleNum = 0;

    // Iterate to see which number minus the others is 0, if none ar then that your number
    while (numsPtr < numsSentinel) {
        singleNum ^= *numsPtr;
        numsPtr++;
    }

    return singleNum;
}

int leet1_test2() {
    int foo[3] = {2, 2, 1};
    std::cout << "{2, 2, 1}=" << singleNumber2(foo, 3) << std::endl;

    int foo2[5] = {4,1,2,1,2};
    std::cout << "{4,1,2,1,2}=" << singleNumber2(foo2, 5) << std::endl;

    int foo3[5] = {1,3,1,-1,3};
    std::cout << "{1,3,1,-1,3}=" << singleNumber2(foo3, 5) << std::endl;

    return 0;
}
