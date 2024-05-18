#!/bin/bash

# Run with a valid graph
echo "4
0 10 2147483647 30
2147483647 0 50 2147483647
2147483647 2147483647 0 20
2147483647 2147483647 10 0
0" | ./dijkstra

# Run with a graph having too many edges
echo "3
0 10 20 30
0" | ./dijkstra

# Run with a graph having negative weights
echo "3
0 10 -5
2147483647 0 20
2147483647 2147483647 0
0" | ./dijkstra

# Run with an invalid start vertex
echo "3
0 10 20
2147483647 0 20
2147483647 2147483647 0
-1" | ./dijkstra

# Run with too many vertices
echo "4
0 10 20 30
0" | ./dijkstra

# Run with zero vertices to exit
echo "0" | ./dijkstra

# Additional tests

# Run with too few edges
echo "3
0 10
2147483647 0
2147483647 2147483647 0
0" | ./dijkstra

# Run with invalid characters in matrix
echo "3
0 10 20
2147483647 x 20
2147483647 2147483647 0
0" | ./dijkstra

# Run with start vertex out of range (high)
echo "3
0 10 20
2147483647 0 20
2147483647 2147483647 0
3" | ./dijkstra

# Run with start vertex out of range (negative)
echo "3
0 10 20
2147483647 0 20
2147483647 2147483647 0
-5" | ./dijkstra

# Run with graph with INF represented by large value
echo "3
0 10 2147483647
2147483647 0 20
2147483647 2147483647 0
0" | ./dijkstra

# Run with large number of vertices
echo "101
0" | ./dijkstra

# Run with large number of edges
echo "2
0 10 20
2147483647 0
0" | ./dijkstra
