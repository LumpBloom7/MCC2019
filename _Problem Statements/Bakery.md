# Bakery

### Problem Statement
MCC bakery has a promotion:

> When you buy 4 pieces of bread, the second cheapest one is free of charge!

You want to buy *n* pieces of bread (where *n* is a multiple of 4) and are given the price of each bread you want to buy. What is the minimum amount you have to pay to purchase all the bread?

### Input Format
You will be given a list of numbers `prices` indicating the price of each bread you want to buy. It is guaranteed that the length of prices is a multiple of 4.

### Output Format
The minimum amount you have to pay to purchase all the bread.

### Sample
#### Input
```
3 2 6 8 10 1 7 9
```
#### Output
```
35
```

### Explanation

You can buy in 2 batches (2,8,10,9) to get the one that costs 8 free and (3,6,1,7) to get the one that costs 3 free. In the end you only have to pay 2+10+9+6+1+7=35.