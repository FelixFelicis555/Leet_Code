In preorder sequence,leftmost element is the root of the binary tree,by searching that element in the inorder sequence,we would know the nodes that are present in left & right sub-tree.
The nodes that lie left side of root in inorder -left-subtree
The nodes that lie right side of root in inorder-Right subtree
So,we will pick an element from pre-order in each recursive call ,so we need to get increment that value to take next element
This will be done recursively