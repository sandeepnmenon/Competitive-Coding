# Python3 Program for Floyd Warshall Algorithm
 

# Define infinity as the large
# enough value. This value will be
# used for vertices not connected to each other
INF = 99999
 
# Solves all pair shortest path
# via Floyd Warshall Algorithm
 
 
def floydWarshall(graph, V):
    """ dist[][] will be the output
       matrix that will finally
        have the shortest distances
        between every pair of vertices """
    """ initializing the solution matrix
    same as input graph matrix
    OR we can say that the initial
    values of shortest distances
    are based on shortest paths considering no
    intermediate vertices """
 
    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
 
    """ Add all vertices one by one
    to the set of intermediate
     vertices.
     ---> Before start of an iteration,
     we have shortest distances
     between all pairs of vertices
     such that the shortest
     distances consider only the
     vertices in the set
    {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a
      iteration, vertex no. k is
     added to the set of intermediate
     vertices and the
    set becomes {0, 1, 2, .. k}
    """
    for k in range(V):
 
        # pick all vertices as source one by one
        for i in range(V):
 
            # Pick all vertices as destination for the
            # above picked source
            for j in range(V):
 
                # If vertex k is on the shortest path from
                # i to j, then update the value of dist[i][j]
                if dist[i][k] + dist[k][j] < dist[i][j] and dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = dist[i][k] + dist[k][j]

    # printSolution(dist, V)
    return dist

 # Solves all pair shortest path that uses an even number of edges
# via Floyd Warshall Algorithm
def floydWarshallEven(graph, V):
    # For every vertex in graph add another vertex with a zero edge to it
    # and run floyd warshall algorithm
    
    # Create a new graph with 2V vertices
    newGraph = [[INF for column in range(2*V)]
                for row in range(2*V)]
    
    # Copy the edges from the original graph to the new graph
    for i in range(V):
        for j in range(V):
            newGraph[i][j+V] = graph[i][j]
            newGraph[i+V][j] = graph[i][j]

    dist = floydWarshall(newGraph, 2*V)

    return dist    

 # Driver program to test the above program
 
# A utility function to print the solution
def printSolution(dist, V):
    print("Following matrix shows the shortest distances\
 between every pair of vertices")
    for i in range(V):
        for j in range(V):
            if(dist[i][j] == INF):
                print("%7s" % ("INF"), end=" ")
            else:
                print("%7d\t" % (dist[i][j]), end=' ')
            if j == V-1:
                print()
 
 
# Driver's code
if __name__ == "__main__":
  """
              10
         (0)------->(3)
          |         /|\
        5 |          |
          |          | 1
         \|/         |
         (1)------->(2)
              3           """
  # Number of vertices in the graph
  V = 4
 
  graph = [[INF, 5, INF, 10],
         [INF, INF, 3, INF],
         [INF, INF, INF,   1],
         [INF, INF, INF, INF]
         ]
  # Function call
  printSolution(floydWarshall(graph, V), V)
  printSolution(floydWarshallEven(graph, V), V)
