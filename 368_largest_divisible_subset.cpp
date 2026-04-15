#include <algorithm>
#include <iostream>
#include <vector>
// Given a set of distinct positive integers nums, return the largest subset
// answer such that every pair (answer[i], answer[j]) of elements in this subset
// satisfies:
//
//     answer[i] % answer[j] == 0, or
//     answer[j] % answer[i] == 0
//
// If there are multiple solutions, return any of them.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
//
// Example 2:
//
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
//
//
//
// Constraints:
//
//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 2 * 109
//     All the integers in nums are unique.

class Solution {
public:
  std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> pointers(nums.size(), -1);
    std::vector<int> lengths(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums.at(i) % nums.at(j) == 0 && lengths.at(j) + 1 > lengths.at(i)) {
          lengths.at(i) = lengths.at(j) + 1;
          pointers.at(i) = j;
        }
      }
    }
    auto max_len = std::max_element(lengths.begin(), lengths.end());
    int index = std::distance(lengths.begin(), max_len);
    std::vector<int> result(*max_len);
    int pos = *max_len - 1;
    while (index != -1) {
      result.at(pos--) = nums.at(index);
      index = pointers.at(index);
    }
    return result;
  }
};
int main() {
  Solution sol;
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 30, 45, 90, 180};
  std::vector<int> v = sol.largestDivisibleSubset(nums);
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
