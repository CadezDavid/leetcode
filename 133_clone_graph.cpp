#include <unordered_map>
#include <vector>

// Given a reference of a node in a connected undirected graph.
//
// Return a deep copy (clone) of the graph.
//
// Each node in the graph contains a value (int) and a list (List[Node]) of its
// neighbors.
//
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
//
//
//
// Test case format:
//
// For simplicity, each node's value is the same as the node's index
// (1-indexed). For example, the first node with val == 1, the second node with
// val == 2, and so on. The graph is represented in the test case using an
// adjacency list.
//
// An adjacency list is a collection of unordered lists used to represent a
// finite graph. Each list describes the set of neighbors of a node in the
// graph.
//
// The given node will always be the first node with val = 1. You must return
// the copy of the given node as a reference to the cloned graph.

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;

    std::unordered_map<Node *, Node *> cloned;
    Node *clone = new Node(node->val);
    Node *curr_clone = clone;
    std::vector<Node *> todo{node};
    cloned.insert({node, clone});
    while (!todo.empty()) {
      Node *curr = todo.back();
      todo.pop_back();

      // Get the clone for the node we are currently processing
      Node *curr_clone = cloned[curr];

      for (Node *neighbor : curr->neighbors) {
        if (cloned.find(neighbor) == cloned.end()) {
          // 1. Create clone
          Node *new_neighbor = new Node(neighbor->val);
          cloned[neighbor] = new_neighbor;
          // 2. Add to stack to process its neighbors later
          todo.push_back(neighbor);
        }
        // 3. Link the clones together
        curr_clone->neighbors.push_back(cloned[neighbor]);
      }
    }
    return clone;
  }
};

int main() {
  Solution sol;
  Node *node_1 = new Node(1);
  Node *node_2 = new Node(2);
  Node *node_3 = new Node(3);
  Node *node_4 = new Node(4);
  node_1->neighbors.push_back(node_2);
  node_1->neighbors.push_back(node_3);
  node_2->neighbors.push_back(node_1);
  node_2->neighbors.push_back(node_4);
  node_3->neighbors.push_back(node_4);
  node_3->neighbors.push_back(node_1);
  node_4->neighbors.push_back(node_2);
  node_4->neighbors.push_back(node_3);
  sol.cloneGraph(node_1);

  return 0;
}
