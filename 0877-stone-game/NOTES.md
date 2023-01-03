As given  in the problem,total no of stones is odd this  draws some facts that either  sum(even-indices) or sum(odd-indices) is higher
​
There is no possibility of result would end up tie,If alice keeps on picking stones from even indices then bob always left with odd-indices
​
Alex had 2 choices ,either she can pick all stones from even indices or odd indices,so alex always wins the game
​
If we think this problem in terms of recursion so i will make a function f(),this will return difference b/w total no of stones occupied by alex and bob respectively
​
We've 2 options either we can pick from  0 or n-1. So  we always try to choose max among two choices
max(A[0]-f(1,n-1),A[n-1]-F(0,n-2))