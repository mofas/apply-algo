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
