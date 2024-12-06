Populating Next Right Pointers in Each Node (Please refer to the docx version of README for better understanding)


A perfect binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.

Given a perfect binary tree which contains an extra next pointer in all the node, populate the next pointers of each node to its next right node.

In nodes with no right nodes, set next to null.

Example
tree-next-pointer
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 2 lines:

The first line contains an integer n denoting the number of nodes in the tree.
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree.
Output Format
For each test case, the output has two lines:

The first line contains the number of nodes in the tree.
The second line contains space-separated integers denoting the level order traversal of the tree done using the next pointer for each level.
Sample Input
4
1
1
3
1 3 2
7
3 5 6 1 2 7 4
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Expected Output
1
1
3
1 3 2
7
3 5 6 1 2 7 4
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15