#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Given a string s, find the length of the longest substring without repeating characters.
*/
#define CHAR_SIZE 128
//function declaration
int lengthOfLongestSubstring(char* s);

int main() {
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("The length of the longest substring without repeating characters is: %d\n", result);
}

//function definition
int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int result = 0;
    int left = 0;

    int index[CHAR_SIZE];
    for (int i = 0; i < CHAR_SIZE; i++) {
        index[i] = -1;
    }
    // pwwkew
    //[-1,-1,-1,-1,-1,-1]
    // current = s[0] = p -> right 0 left 0 -> check index[current] = -1 -> set index[current] = right = 0 -> index[s.value] = [0,-1,-1,-1,-1,-1]
    // currentVal = 0 - 0 + 1 -> currentVal > result -> result = currentVal = 1
    // current = s[1] = w -> right 1 left 0 -> check index[current] = -1 -> set index[current] = right = 1 -> index[s.value] = [0,1,-1,-1,-1,-1]
    // currentVal = 1 - 0 + 1 -> currentVal > result -> result = currentVal = 2
    // current = s[2] = w -> right 2 left 0 -> check index[current] = 1 -> index[current] > left -> left = index[current] + 1 = 2 ->set index[current] = 2 -> index[s.value] = [0,1,2,-1,-1,-1]
    // currentVal = 2 - 2 + 1 = 1 -> result = 2 -> pw  currentVal = 1 -> w 

    for (int right = 0; right < n; right++) {
        char current = s[right];

        if (index[current] >= left) {
            left = index[current] + 1;
        }

        index[current] = right;

        int currentVal = right - left + 1;
        if (currentVal > result) {
            result = currentVal;
        }
    }
    return result;
}