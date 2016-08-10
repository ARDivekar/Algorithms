/*
Modification of http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/:
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (dest_x, dest_y) from (source_x, source_y). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (dest_x, dest_y) is sum of all the costs on that path (including both source and destination).
You can traverse in any of the four directions from a given cell, i.e., from a given cell (i, j), cells (i-1, j), (i+1, j), (i, j-1) and (i, j+1) can be traversed. You may assume that all costs are positive integers.
For example, in the following figure, what is the minimum cost path to from (0,2) to (1,0)?
    {1, 2, 3}
    {4, 8, 2}
    {1, 5, 3}
The path is (0, 0) –> (0, 1) –> (1, 2) –> (2, 2).
The cost of the path is 8 (1 + 2 + 2 + 3).


SOLUTION: Map to Dijkstra's algo and use that.
*/
