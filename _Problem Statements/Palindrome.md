# Elimination

### Problem Statement
A palindrome is a string that is identical when read from left to right and from right to left. For example, `"racecar"` and `"0110"` are palindromes.

A string is called a *k-palindrome* if it is a palindrome and also each character is either **0,1,...** or **k−1** for some **2≤k≤10**. For example. `"302203"` is a *4-palindrome*, *5-palindrome*, *6-palindrome* and so on, but it is not a *2-palindrome* and also not a *3-palindrome*.

Bob came across a book titled **k** for some **2≤k≤10**. It has an infinite margin and consists of all possible k-palindromes. The book arranges the palindromes in a list in the following fashion:

1. If two strings are different in length, the shorter one goes first
2. If they are the same in length, the lexicographically smaller string goes first, like in dictionaries.

For example, the first 10 words in book 2 will be:
```
0
1
00
11
000
010
101
111
0000
0110
```

Bob wonders what is **n<sup>th</sup>** string in the book. Can you help him out?

### Input Format
You will be given two numbers, `n` and `k`, the position (1-index) of the word Bob is interested in and the title of the book.

### Output Format
Output the **n<sup>th</sup>** string in the book.

### Sample
#### Input
```
7
3
```
#### Output
```
000
```

### Explanation

The first 7 words of the book `3` are as follow:
```
0
1
2
00
11
22
000
```
So the **7<sup>th</sup>** word is `"000"`.