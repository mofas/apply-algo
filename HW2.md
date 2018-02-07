# 1. Illustrate the operation of Heap_extract_max on the heap A=<15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1>

We will move the max to end of array, and remove it. So we will have,

```
1, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2
```

The we will need to do heapify on position 1, l: 2, r: 3, (we start from index 1).

```
13, 1, 9, 5, 12, 8, 7, 4, 0, 6, 2
```

On position 2, 4, 5

```
13, 12, 9, 5, 1, 8, 7, 4, 0, 6, 2
```

On position 5, 10, 11

```
13, 12, 9, 5, 6, 8, 7, 4, 0, 1, 2
```

And we done.

# 2. You are given an array of n elements, and you notice that some of these elements are duplicates; that is they appear more than one time in the array. Devise an algorithm to remove all duplicates from the array in time O(n log n).

We sorted it at first. It cost O(n log n) time.
Than we scan the array again, and remove all items which have the same value as the previous one, which cost O(n).

```
prev <- a[0]
int i = 1;
while (i < a.length - 1)
  if (a[i] === prev)
    remove a[i]
  else
    prev <- a[i]
  i++
```

# 3. A sequence of n operations is performed on a data structure. The ith operation costs i if i is an exact power of 2, and 1 otherwise. Use aggregate analysis to determine the amortized cost per operation.

The special cost will at sequence.

```
1, 2, 4, 8, 16, 32 ....
```

There are (log2 n) + 1 times, that i will equal to power of 2.

The total cost will be,

```
// for all other constant cost
sum <- (n - log2 n) * 1

// for special cost
for (i <- 1 to (log2 n) - 1)
  sum <- sum + 2^i
```

The total cost will be ~ `n + 2*n = 3*n`.
That is O(n)

# 4. A sequence of stack operations is performed on a stack whose size never exceeds k. After every k operations, a copy of the entire stack is made for backup purposes. Show that the cost of n stack operations, including copying the stack, is O(n) by assigning suitable amortized costs to the various stack operations.

Stack has two operation, push and pop.
Everytime we do those operations, we can do the same thing on another "backup" stack.
After k operations, we can switch to another new "backup" stack.

Therefore, all operation double the cost from original one, so the total cost is `2*n`.
However, the cost is still O(n). (Create new backup stack will be constant cost, and that cost is also O(n)).

# 5. Suppose we wish not only to increment a counter but also to reset it to zero (i.e., make all bits in it 0). Show how to implement a counter as an array of bits so that any sequence of increment or reset operations takes time O(n) on an initially zero counter.

# 6. What is the total cost of executing n of the stack operations PUSH, POP, and MULTIPOP, assuming that the stack begins with s0 objects and finishes with sn objects?

# 7. Illustrate the insertion of the keys 5, 28, 19, 15, 20, 33, 12, 17, 10 into a hash table with collisions resolved by chaining. Let the table has 9 slots, and let the hash function be h(k) = k mod 9.

```
[0]
[1]
[2]
[3]
[4]
[5] 5
[6]
[7]
[8]

[0]
[1] 27
[2]
[3]
[4]
[5] 5
[6]
[7]
[8]

[0]
[1] 28 -> 19
[2]
[3]
[4]
[5] 5
[6]
[7]
[8]

[0]
[1] 28 -> 19
[2]
[3]
[4]
[5] 5
[6] 15
[7]
[8]

[0]
[1] 28 -> 19
[2] 20
[3]
[4]
[5] 5
[6] 15
[7]
[8]

[0]
[1] 28 -> 19
[2] 20
[3]
[4]
[5] 5
[6] 15 -> 33
[7]
[8]

[0]
[1] 28 -> 19
[2] 20
[3] 12
[4]
[5] 5
[6] 15 -> 33
[7]
[8]

[0]
[1] 28 -> 19
[2] 20
[3] 12
[4]
[5] 5
[6] 15 -> 33
[7]
[8] 17


[0]
[1] 28 -> 19 -> 10
[2] 20
[3] 12
[4]
[5] 5
[6] 15 -> 33
[7]
[8] 17
```
