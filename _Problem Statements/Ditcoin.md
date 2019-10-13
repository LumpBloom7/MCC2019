# Ditcoin

### Problem Statement
You earn one Ditcoin every day. You also know the future price of the ditcoin. A ditcoin earned on that day can be sold on that day or in the future days. You can sell any amount of ditcoin on a given day. Your task is to compute the maximum amount of money you can earn by selling your ditcoins optimally.

### Input Format
You are given a list of prices `prices` indicating the amount you can earn if you sell a ditcoin on that day.

### Output Format
The maximum amount of money you can earn.

### Sample
#### Input
```
3 2 6 8 10 1 7 9
```
#### Output
```
77
```

### Explanation

If you sell your 1st to 5th ditcoin of the 5th day, you earn 5×10=50, and the rest on the last day to earn 3×9=27 more. In total, you will earn 77.