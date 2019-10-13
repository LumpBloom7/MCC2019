# Candy

### Problem Statement
Cindy is a very generous teacher and decides to give out a piece of candy to one of her infinite number of students! She has created a game to help her select which student to give the candy to.

The game consists of *N* rounds. The game goes as follow:

1. All of her students are queuing in a line. Then they start the first round.

2. Cindy will either shout `"odd"` or `"even"`.

3. If she shouted `"odd"`, all the students currently standing at odd-numbered positions are eliminated from the game. Similarly, if she shouted `"even"` all the students currently standing at even-numbered positions are eliminated from the game. Students who are eliminated will no longer be in the queue.

4. The remaining surviving students will play again without switching places from step 2 for another round, or stop playing if *N* rounds have been played.

After *N* rounds, Cindy will give the candy to the first student in the queue.

Bob knows what Cindy will shout at each round and really wants the candy. He wonders where should he stand in the queue initially (round 1) so that he can get the candy. Can you help Bob?
### Input Format
You will be given a list shouts, with *N* strings of either `"even"` or `"odd"`. The *i*<sup>th</sup> item in the list is what Cindy will shout on the *i*<sup>th</sup> round.

### Output Format
Output the number of the position Bob should stand at the start of the game.

### Sample
#### Input
```
even even odd
```
#### Output
```
5
```

### Explanation

We can illustrate the process of the game. Let’s label each student by the number of their initial position, and Bob’s number, `5` in this case, is marked with an asterisk (*).
```
Initial queue:
1, 2, 3, 4, 5*, 6, 7, ...

Queue after round 1 ("even" shouted):
1, 3, 5*, 7, 9, 11, 13, ...

Queue after round 2 ("even" shouted):
1, 5*, 9, 13, 17, 21, ...

Queue after round 3 ("odd" shouted):
5*, 13, 21, ...
```
Bob is the first student after the game, and he was awarded the candy!