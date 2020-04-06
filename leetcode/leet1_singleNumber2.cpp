#include <iostream>

int singleNumber2 (int *nums, int numsSize)
{
  // assert nums and numSize > 0

  int *numsSentinel = nums + numsSize;
  int *numsPtr = nums;
  int singleNum = 0;

  // Iterate to see which number minus the others is 0, if none ar then that your number
  while (numsPtr < numsSentinel) {
    int *numsPtrTest = nums;
    int matchFound = 0;
    while (numsPtrTest < numsSentinel) {
      if (numsPtrTest != numsPtr) {
        if ((*numsPtr - *numsPtrTest) == 0) {
          // Match found so cant be this one
          matchFound = 1;
          break;
        }
      }
      numsPtrTest++;
    }
    if (!matchFound)
      singleNum = *numsPtr;

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
