#include "euler_characteristic.h"
#include <set>
#include <algorithm>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  // ADD YOUR CODE HERE
  // record the number of vertices
  std::set<int> unique_vertices;
  for (int i = 0; i < F.rows(); ++i) {
    unique_vertices.insert(F(i, 0));
    unique_vertices.insert(F(i, 1));
    unique_vertices.insert(F(i, 2));
  }
  // record the number of edges
  std::set<std::pair<int, int>> unique_edges;
  for (int i = 0; i < F.rows(); ++i) {
    int v0 = F(i, 0);
    int v1 = F(i, 1);
    int v2 = F(i, 2);
    unique_edges.insert(std::minmax(v0, v1));
    unique_edges.insert(std::minmax(v1, v2));
    unique_edges.insert(std::minmax(v2, v0));
  }

  int V = unique_vertices.size();
  int E = unique_edges.size();
  int num_faces = F.rows();
  auto Chi = V - E + num_faces;
  
  return Chi;
}
