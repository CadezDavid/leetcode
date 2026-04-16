#include <iostream>
#include <vector>

int optimal(const std::vector<int> &values) {
  int n = values.size();
  std::vector<std::vector<int>> memo(n, std::vector<int>(n, 0));

  for (int d = 0; d < n; d++) {
    for (int i = 0; i + d < n; i++) {
      if (d < 2) {
        memo[i][i + d] = std::max(values[i], values[i + d]);
      } else {
        memo[i][i + d] = std::max(
            values[i] + std::min(memo[i + 1][i + d - 1], memo[i + 2][i + d]),
            values[i + d] +
                std::min(memo[i + 1][i + d - 1], memo[i][i + d - 2]));
      }
    }
  }

  return memo[0][n - 1];
}

int main() {
  std::vector<int> values{5, 3, 4, 5};
  std::cout << optimal(values) << std::endl;
}
