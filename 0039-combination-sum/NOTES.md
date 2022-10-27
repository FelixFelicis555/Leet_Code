So the problem is to print all the combinations,whenever there's a question related to  printing combinations & subsequences,The first thing that strikes to our mind is Recursion.
​
Obviously the problem will be solved by recursion.
​
How do you start think of recursion or How will you write recursive-code?
​
At first,whenever there's a problem related to picking up elements from an array to form combination.
​
We start thinking whether we can pick or not pick .We are in that thought process
​
So whenever there's a problem related to array,You need to figure out all the combinations from it. We always go through this pick-not pick procedure.
​
We have to decide at every index,whether we are picking it & how many times we can pick
​
So our recursive function has following parameters:
a) current_index
b) target_sum that we are looking for
c)Maintain some data-structurewhich stores current-valid combination