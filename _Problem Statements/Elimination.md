# Elimination

### Problem Statement
A binary string is a string where each character is either `0` or `1`.

Given a binary string and a number *k*, find the length of the longest consecutive **1′s** after removing at most k **0′s** from the binary string.

### Input Format
You will be given a binary string `string` and a number `k`.

### Output Format
Output the length of the longest consecutive 1’s after removing at most `k` 0’s.

### Sample
#### Input
```
101111001110111
1
```
#### Output
```
6
```

### Explanation

We can remove the 0 between the 2 `"111"` substring to get `"111111"` as a substring. This is clearly the longest consecutive 1’s we can get.