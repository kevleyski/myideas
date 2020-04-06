#include <iostream>
#include <cstdlib>

/* Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
 */

struct map {
    int hash;
    char* str;
};

int compar(const void *left, const void *right) {
    struct map* left_map = (struct map*)left;
    struct map* right_map = (struct map*)right;
    return left_map->hash < right_map->hash;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

    // assert strs, returnSize, returnColumnSizes
    int* returnColumnSizesAlloc = (int*)malloc(50 * sizeof(int*));
    memset(returnColumnSizesAlloc, 0, 50 * sizeof(int*));
    *returnColumnSizes = returnColumnSizesAlloc;

    // a basic hash sum of the ascii code determines which are anagrams
    // and we need to sort them to group them

    int* hashes = (int*)malloc(strsSize * sizeof(int));
    // asset hashes
    memset(hashes, 0, strsSize * sizeof(int));
    char** strsPtr = strs;
    char** strsPtrSentinel = strsPtr + strsSize;

    int* hashesPtr = hashes;
    while (strsPtr < strsPtrSentinel) {
        // hash
        char* thisStringPtr = *strsPtr;
        while (*thisStringPtr) {
            *hashesPtr += *thisStringPtr;
            thisStringPtr++;
        }
        hashesPtr++;
        strsPtr++;
    }

    // Create map
    struct map* stringsMap = (struct map*)malloc(strsSize * sizeof(struct map));
    // assert stringsMap
    memset(stringsMap, 0, strsSize * sizeof(struct map));
    hashesPtr = hashes;
    struct map* stringMapPtr = stringsMap;
    struct map* stringMapPtrSentinel = stringsMap + strsSize;
    strsPtr = strs;
    while (strsPtr < strsPtrSentinel) {
        stringMapPtr->hash = *hashesPtr;
        stringMapPtr->str = *strsPtr;
        stringMapPtr++;
        hashesPtr++;
        strsPtr++;
    }

    // Sort map by hash
    qsort(stringsMap, strsSize, sizeof(struct map), compar);

    // build return value
    *returnSize = 0;
    returnColumnSizes = 0;

    // Lowest to highest
    int* returnColumnSizesPtr = returnColumnSizesAlloc;

    // Create column for each set of same hash
    int idx = 0;
    int col = 0;

    stringMapPtr = stringsMap;
    int thisHash = stringMapPtr->hash;
    char*** retval = (char***)malloc(50 * sizeof(char***));
    memset(retval, 0, 50 * sizeof(char***));
    retval[idx] = (char**)malloc(50 * sizeof(char**));
    memset(retval[idx], 0, 50 * sizeof(char**));
    while (stringMapPtr < stringMapPtrSentinel) {
        if (thisHash != stringMapPtr->hash) {
            // create new column
            returnColumnSizesPtr++;
            idx++;
            retval[idx] = (char**)malloc(50 * sizeof(char**));
            memset(retval[idx], 0, 50 * sizeof(char**));
            col = 0;
        }
        retval[idx][col] = stringMapPtr->str;
        col++;
        *returnColumnSizesPtr = col;
        thisHash = stringMapPtr->hash;
        stringMapPtr++;
    }

    *returnSize = idx + 1;

    // free temps
    free(stringsMap);
    free(hashes);

    return retval;
}

int leet3_test() {
//    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
// expected [["bat"],["nat","tan"],["ate","eat","tea"]]

    char* strs[] = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
// expected [["doc"],["bar"],["buy"],["ill"],["may"],["tin"],["cab"],["pew"],["max"],["duh"]]

    int retSize = 0;
    int* returnColumnSizes = NULL;
    char*** retval = groupAnagrams(strs, sizeof(strs) / sizeof(char*), &retSize, &returnColumnSizes);


    std::cout << "retSize=" << retSize << std::endl;

    return 0;
}
