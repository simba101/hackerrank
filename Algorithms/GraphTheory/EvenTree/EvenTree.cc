/*
Solution to the "EvenTree" challenge by HackerRank:
https://www.hackerrank.com/challenges/even-tree
Written on 07-12-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>

const int MAX_NODES_COUNT = 100;
const int UNINITIALIZED = -1;

// Represents a node in a tree.
class Node
{
 public:
  Node() : _visited(false), _volume(UNINITIALIZED) {}

 public:
  int _volume; // tells how many edges are in a subtree rooted in this node.
  bool _visited;
  std::vector<int> _neighbors;
};

static Node nodes[MAX_NODES_COUNT + 1];

// Marks every node in the entire tree as an un-visited one.
void unvisit(int treeSize)
{
  for(int n = 1; n <= treeSize; ++n)
  {
    nodes[n]._visited = false;
  }
}

int get_subtree_volume(int nodeIndex)
{
  // currying:
  if(nodes[nodeIndex]._volume != UNINITIALIZED)
  {
    return nodes[nodeIndex]._volume;
  }

  // marks this node as already visited:
  nodes[nodeIndex]._visited = true;

  // the subtree consisting of this node itself has the volume of 1.
  nodes[nodeIndex]._volume = 1;

  // but if there are unvisited neighbor nodes, their volumes need to be added:
  for(int n = 0; n < nodes[nodeIndex]._neighbors.size(); ++n)
  {
    int neighbor = nodes[nodeIndex]._neighbors[n];
    if(!nodes[neighbor]._visited)
    {
      nodes[nodeIndex]._volume += get_subtree_volume(neighbor);
    }
  }

  // finally, returns the volume of the subtree rooted in nodeIndex:
  return nodes[nodeIndex]._volume;
}

int get_removable_edges_count(int rootNode, int treeSize)
{
  int ans = 0;
  for(int n = 1; n <= treeSize; ++n)
  {
    if(n != rootNode)
    {
      if ((nodes[n]._volume > 0) && (nodes[n]._volume % 2 == 0))
      {
        // This node may be disconnected from the parent tree:
        ans += 1;
      }
    }
  }

  return ans;
}


int main(int argc, char **argv)
{
  int nodesCount, edgesCount;
  std::cin >> nodesCount >> edgesCount;

  // Reads in the two nodes' indices that share an edge, constructing a tree:
  for(int e = 0; e < edgesCount; ++e)
  {
    int a, b;
    std::cin >> a >> b;
    nodes[a]._neighbors.push_back(b);
    nodes[b]._neighbors.push_back(a);
  }

  // The tree is rooted in node 1, but anyway, it's a tree, any index could
  // be used.
  // 1 is always guaranteed to exist, though, so it will be used anyway.
  unvisit(nodesCount);
  get_subtree_volume(1);

  unvisit(nodesCount);
  int ans = get_removable_edges_count(1, nodesCount);
  std::cout << ans << std::endl;

  return 0;
}
