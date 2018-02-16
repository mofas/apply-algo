#### 1. For the set of {1, 4, 5, 10, 16, 17, 21} of keys, draw binary search trees of height 2, 3, 4, 5, and 6.

* Height 2

```
       10
    4     17
  1   5 16   21
```

* Height 3

```
       10
    4     16
  1   5      17
                 21
```

* Height 4

```
      5
    4   10
  1        16
        17    21
```

* Height 5

```
      5
    4   10
  1        16
              17
                 21
```

* Height 6

```
      4
    1   5
          10
             16
                17
                   21
```

#### 2. Suppose that the search for the key kin a binary search tree ends up in a leaf. Consider three sets: 1) the keys to the left of the search path; 2) the keys on the search path; 3) the keys to the right of the search path. One claims that any three keys a, b and c from these three sets, respectively (say a from 1, b from 2 and c from 3), it is always true that a ≤ b ≤ c. Is this claim true? Explain your answer.

No. Consider we serach for 3 in the following tree. Then a ∈ { 1 }, b ∈ { 2, 3, 4, 6 }, c ∈ { 5 }
It is clear we can pick a = 1, b = 6 and c = 5 which violate a ≤ b ≤ c.

```
       2  
   1        6
          4
        3   5
```

#### 3. We can sort a given set of n numbers by first building a binarysearchtree containing these numbers (using Tree_insert algorithm repeatedly to insert the numbers on by one) and then printing the number in an inorder tree walk. What are the worst-case and best-case running times for this sorting algorithm?

We know the running time for inserting is proportional to the hight of tree.

Therefore, in the best case, we have nearly balance tree and the hight of that tree is equal to log n. Hence, the running time for best case is `∑ (log i + d)`, which i from 1 to n, and d is const cost. Accordingly, the total cost is `O(n*log n)`.

For worst case, we have complete biased linear tree, When we insert the nth element to the tree, the hight of the tree is n-1. Hence, the cost is `∑ ((i-1) + d)` which i from 1 to n, and d is const cost. Accordingly, the total cost is `O(n^2)`.

#### 4. Suppose two teams A and B are playing a match to see who is the first to win n games (from given n). Assume that A and B are equally competent, so each has a 50% chance of winning any particular game. Suppose they have already played i+j games, of which A won i and B has won j. Given an efficient algorithm to compute the probability that A will go on to win the match. For example, if i=n-1 and j=n-3 then the probability that A will win the match is 7/8, since it must win any of the next three games.

Assume x, y be the remaining games team A, B need to win, then x = n - i, y = n - j.

P(x, y) be the change the team A will win.

For P(1, 1), we know team A has 0.5 to win the match, because A have 50% to win a game.
For P(1, 2), We know there is 0.5 that Team A will win next game and win the match, and 0.5 that Team A will lose the game and fallback to P(1, 1) sceniaro.

Accordingly, We can get formula that `P(1, 1) = 0.5 + 0.5*P(1, 2)`.
We can use induction to get general relation `P(1, y) = 0.5 + 0.5*P(1, y+1)`.
Due to the rule of symmetry, we also know that P(2, 1) is also equal to `0.5 + 0.5*P(1, 1)` as well.

In fact, we can get the overall recursion function that.
`P(x, y) = 0.5*P(x-1, y) + 0.5*P(x, y-1)` and `P(1, 1) = 0.5`.

Or we can replace the parameter back to get
`P(n-i, n-j) = 0.5*P(n-i+1, n-j) + 0.5*P(n-i, n-j+1)` and `P(n-1, n-1) = 0.5`.

Then we can use dynamic programming to solve this recursion.

#### 5. Give an O(nt) algorithm for the following task. Input: a list of n positive integers a1, a2, ..., an; a positive integer t.Question: does some subset of the ai’s add up to t?
