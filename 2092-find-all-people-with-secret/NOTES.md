Visit the meetings happening at the same time together.
​
We can connect the two persons in the same meeting using a UnionFind.
​
Tricky point here: After traversing this batch of meetings, we reset the persons who don't know the secret by checking if he/she is connected to person 0. With UnionFind, reseting means setting id[x] = x.
​
In the end, we add all the persons who are connected to person 0 into the answer array.