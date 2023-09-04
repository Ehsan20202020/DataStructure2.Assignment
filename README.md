# DataStructure2.Assignment
Once the program is running, it will read the file "" 
which consists of numbers between 0 and 256, with each number separated by a space.
While reading each line from the file, numbers will be added to a Stack (Yığın).
When a new number is read from the file
and it is greater than the number at the top of the Stack being processed,
it will be added to a new Stack.
Otherwise, it will continue to be added to the existing Stack (Yığıt).
After each line in the file is read,
the elements in the Stack will be emptied and added to a separate Binary Search Tree.
If there is already a node with the same value in the tree, that value will not be added again.
For each line, the number of Binary Search Trees
created will be equal to the number of Stacks (Yığıt) in that line.
Among the generated Binary 	Search Trees, the one with the maximum height will be selected.
In case of equal heights, the tree with the largest sum of node values will be chosen.
If the total values are also equal, the tree created first will be selected.
The selected Binary Search Tree with the maximum height will be read in postorder, and the ASCII
representations of the numeric values will be displayed
on the screen with a space between them.
The program will wait for 10 milliseconds (using the "sleep" function) before applying the same process for the next line.
The program will end when it finishes reading the file.
