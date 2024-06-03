
/*
	* Question 4 implementation.
	This programs main purpose is to show the usage of gcov(1).
	* written by Tomer Shor & Adam Sin
	* Date: 10/5/2024
*/


// The program is an implementation of Dijkstra's shortest path algorithm.
// Implementation as shown in the following link: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/


/*
	To run the program:
	$ make coverage

	* The program will try different inputs for the Dijkstra's algorithm written in run_tests.sh.
	* All of the test together should cover all of the code in the program.
*/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX_VERTICES 100
#define INF INT_MAX

// A utility function to find the vertex with minimum distance
// Added number of vertices as a parameter, so that we can use it in the main function.
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int start_vertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < num_vertices; i++) {
        distance[i] = INF;
    }
    distance[start_vertex] = 0;

    for (int i = 0; i < num_vertices - 1; i++) {
        int min_distance = INF, min_index = -1;
        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && distance[v] <= min_distance) {
                min_distance = distance[v];
                min_index = v;
            }
        }

        if (min_index == -1) {
            break; // All remaining vertices are inaccessible from the source
        }

        int u = min_index;
        visited[u] = 1;

        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d\t\t%d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int num_vertices, start_vertex;

    while (1) {
        printf("Enter the number of vertices (0 to exit): ");
        if (scanf("%d", &num_vertices) != 1 || num_vertices <= 0) {
            break;
        }

        if (num_vertices > MAX_VERTICES) {    // Added a check for the number of vertices
            printf("Number of vertices exceeds maximum limit of %d\n", MAX_VERTICES);
            continue;
        }

        printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
        int valid_input = 1;
        int input_count = 0;
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                if (scanf("%d", &graph[i][j]) != 1) {    // Added a check for invalid input
                    valid_input = 0;
                    break;
                }
                input_count++;
                if (graph[i][j] < 0 && i != j || i == j && graph[i][j] != 0) {          // Added a check for negative weights and loop backs
                    valid_input = 0;
                    printf("Negative weights are not allowed in Dijkstra's algorithm and there is no loop backs in the graph\n");
                }
            }
            if (!valid_input) {			// Added a check for invalid input
				printf("Invalid input. Please enter the adjacency matrix again.\n");
                break;
            }
        }

        if (input_count != num_vertices * num_vertices ) {      // Added a check inappropriately sized input
            printf("Invalid input. Expected %d elements but got %d.\n", num_vertices * num_vertices, input_count);
            valid_input = 0;
			break;
        }


        printf("Enter the start vertex: ");
        if (scanf("%d", &start_vertex) != 1 || start_vertex < 0 || start_vertex >= num_vertices) {     	// Added a check for invalid start vertex
            printf("Invalid start vertex\n");
            // Clear the remaining input buffer
            while (getchar() != '\n');
            continue;
        }

        dijkstra(graph, num_vertices, start_vertex);
    }

    return 0;
}
