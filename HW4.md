#### 6. Given two arrays of n integers, the all-pair-sum S is defined as the sum of every pair of elements: S = Σi,jaibj, where ai and bj are the integers in the two respective arrays. Given an array of n integers A, we want to find an array of integers B, in which each element bj ∈ {1, -1}, such that the all-pair-sum between A and B is maximized. How to find array B?

Let the f(j) be the max sum of array A and the array B with first j element.

We know there is only two elements { 1 , -1 } in array B,
and we let SP be the sum of elements in A _ 1 ,and SN be the sum of elements in A _ -1.

Then we can get the following relation

```
f(j+1) = f(j) + max { SP , SN }
```

However, max { SP , SN } is always the same, so we only compute SP, SN once, and based on the result to return array of 1 or array of -1.

#### 7. Given two sorted arrays, each containing n integers, A[1..n] and B[1..n], and an integer N, we want to find two numbers a and b in each of these input arrays, respectively, a∈A and b∈B, such that |a-b|=N; if there are no such two numbers, a message “not found” should be output. Here, we want to avoid any additional storage with the size O(n). Devise an algorithm to find the two numbers in O(n) time under this constraint. (Note that you can still use additional constant memory as temporary storage.)

========= TODO ===========

Let f(A , B, N) be the function search such number, and assume the length of A is n and length of B is m.

We copare the mid of A midA and mid of B midB.

if midA - midB > N, then we recursively search f(A[1..n/2] , B[1...n], N) and f(A[1..n] , B[m/2..m] , N)
else if 0 < midA - midB < N, then we recursively search f(A[n/2..n] , B[1...m], N) and f(A[1..n] , B[1..m/2] , N)
else if midB - midA > N, then we recursively search f(A[1..n] , B[1..m/2] , N) and f(A[n/2..n] , B[1..m] , N)
else if 0 < midB - midA < N, then we recursively search f(A[1..n/2] , B[1...m] , N) and f(A[1..n] , B[m/2..m] , N)

For n = 1 and m = 1, if | A[1] - B[1] | = N, then we find it.

```
[1, 2, 3, 4, 5][2, 3, 4, 15, 16]

| A - B | = 3
```

#### 8. Given an array of n positive integers and an integer N, we want to find if it has a consecutive subarray (i.e., a subarray with consecutive elements between a two positions) with the sum of N. Devise an O(n) algorithm to solve this problem.

Let f(i, j) be the sum from i element to j element in the array A.

We start from f(1, 1) = A[1].

if f(i, j) < N, we go f(i, j+1).
if f(i, j) > N, we go f(i+1, j).

Eg:

```
A = [1, 2, 3, 4, 1, 2, 3]
N = 8

f[1, 1] = 1 < 8  =>
f[1, 2] = 3 < 8  =>
f[1, 3] = 6 < 8  =>
f[1, 4] = 10 > 8 =>
f[2, 4] = 9 > 8  =>
f[3, 4] = 7 < 8  =>
f[3, 5] = 8 == 8
```

The time complexity is 2n, because i and j both from 1 to n, and every step we increase i or j by 1.

#### 9. Given k arrays each with n integers, devise a divide-and-conquer algorithm in O(nklog(nk)) time to find all integers that each appears at least once in each input array. You should use only comparison of the integers, but not use advanced data structures such as hash tables or counting arrays.

We can choose a pivot element "p" from the first array, and split all input array to 3 sub arrays.
the {x < p} , {x = p}, {x > p}. This steps cost `n` times `k` operations.
Then we check if all arrays have at least one elements in the { x = p } sub array. If so, we put p into final result.

And we resursively on subarrays for {x < p} and {x > p}, until one of array in the arrays set is empty.

The expected hight is log(n), just like the parition in quicksort.

I say the total cost can be nklog(n).

Eg:

```
A = [3, 2, 6, 1]
B = [1, 3, 4, 2]
C = [1, 1, 3, 1]

choose 3 as pivot element
split A = [ [2, 1], [3], [6] ]
split B = [ [1, 2], [3], [4] ]
split C = [ [1, 1, 1] [3] [] ]

Then we know 3 appear in all input arrays.

Because one array of the set of {x > 3} arrays is empty, we dont need to handle {x > 3} case anymore.

On {x < 3} recursion,

A' = [2, 1]
B' = [1, 2]
C' = [1, 1, 1]

choose 2 as pivot element

split A' = [ [1], [2], []]
split B' = [ [1], [2], []]
split C' = [ [1, 1, 1] [], []]

Then we know 2 don't appear in all input arrays, so we discard it.

{x > 2} arrays has at least one empty array, we can stop here.

On {x < 2} recursion

A'' = [1]
B'' = [1]
C'' = [1, 1, 1]

choose 1 as pivot element,

split A'' = [ [], [1], []]
split B'' = [ [], [1], []]
split C'' = [ [], [1, 1, 1] []]

we know 1 appear in all elements.

so the final result is [1, 2]
```

#### 10. In an array of n integers A[1..n], the increasing subsequence is a subsequence of k consecutive elements in the array, A[i], A[i+1], …, A[i+k], such that A[i] ≤ A[i+1] ≤ …≤ A[i+k]. Devise a linear time O(n) algorithm to find the longest increasing subsequence of a given array of n integers.

let f(j) be the currently longest sequence that ends at j in array A.
let E be the end index of the longest sequence, and L be the length of the longest sequence.

```
f(1) = 1
E = 1
L = 1

for(i = 2 ; i < length(A); i++){
  if A[i] >= A[i-1] {
    f(i)++;
    if(f(i) >= L){
      L = f(i);
      E = i;
    }
  }
  else  {
    f(i) = 1;
  }
}
```

#### 11. The overlap between two intervals i and i' is defined as: if i ∩ i' ≠ ø, that is, if low[i] ≤ low[i'], overlap = max(0, high[i] - low[i’]); if low[i’] ≤ low[i], overlap = max(0, high[i’] - low[i]). Given a set of intervals S and a query interval q, we want to find the interval in S with the greatest overlap with q. Devise a data structure based on binary search tree (BST) to maintain the interval set S (so that they can be inserte/delected, etc), and a search algorithm using the data structure to solve the above problem in O(log n), where n = |S|. You may modify the BST data structure to incorporate additional auxiliary information.

=========== TODO ============
We sort intervals by low of interval, and we also store the max highest in the node for searching just we do as normal interval tree in textbook. We need to keep those two information for us to search overlay.

In addition, we also need to store the min

Eg

```
[
  [0, 3],
  [5, 8],
  [6, 10],
  [8, 9],
  [15, 23],
  [16, 21],
  [17, 19],
  [19, 20],
  [25, 30],
  [26, 26]
]

target : [8, 18]

goal: [15, 23]
```

#### 12. Given n integers, and a query integer k, we want to computer how many integers among the n integers are greater than k. Assuming we maintain a binary search tree (BST) of the n integers (so that they can be inserted/deleted, etc), we want to solve the above problem in O(h) time, where h is the height of the BST, and for a balanced BST, h=O(log n). Devise an algorithm in O(h) based on the BST of the n integers. You may modify the BST data structure to incorporate additional auxiliary information.

We just need to maintain the number of children in each node.

The insert and delete operations are still the same as BST. The only difference is that, we need to update the children count upward to the root.

For example, the BST with children count is like this.

```
                        (20, 7)
        (14, 2)                       (28, 3)
(11, 0)         (16, 0)      (24, 0)            (31, 1)
                                           (29, 0)
```

For root, (20, 7) means the integer is 20 and this node has 7 children.

If we insert 32 into tree, then we need to increase the children count of node 31, 28, 20 by 1.

```
                        (20, 8)
        (14, 2)                       (28, 4)
(11, 0)         (16, 0)      (24, 0)            (31, 2)
                                           (29, 0)    (32, 0)
```

If we delete 29 from the node, we also need to decrease the children count of node 31 28 20 by 1.

```
                        (20, 6)
        (14, 2)                       (28, 2)
(11, 0)         (16, 0)      (24, 0)            (31, 0)
```

With such data structure, we now can define the function f to calculate the number bigger than k at the root of tree T

```
f(T, k)
  if root[T]  > k
    return f(left[T], k) + childrenCount[right[T]]
  else
    f(right[T], k)
```

Eg:
