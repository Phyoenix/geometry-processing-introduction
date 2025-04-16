#include "edges.h"
#include <set>
#include <vector>
#include <algorithm>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  // ADD YOUR CODE HERE
  std::set<std::pair<int, int>> edge_set;
  
  for (int i = 0; i < F.rows(); ++i) {
    int v0 = F(i, 0);
    int v1 = F(i, 1);
    int v2 = F(i, 2);
    edge_set.insert(std::minmax(v0, v1));
    edge_set.insert(std::minmax(v1, v2));
    edge_set.insert(std::minmax(v2, v0));
  }
  Eigen::MatrixXi E(edge_set.size(), 2);
  int idx = 0;
  for (const auto &edge : edge_set) {
    E(idx, 0) = edge.first;
    E(idx, 1) = edge.second;
    ++idx;
  }
  
  return E;
}
