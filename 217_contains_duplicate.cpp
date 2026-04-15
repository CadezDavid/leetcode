#include <iostream>
#include <unordered_map>
#include <vector>

// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.
//
//
// Example 1:
//
// Input: nums = [1,2,3,1]
//
// Output: true
//
// Explanation:
//
// The element 1 occurs at the indices 0 and 3.
//
// Example 2:
//
// Input: nums = [1,2,3,4]
//
// Output: false
//
// Explanation:
//
// All elements are distinct.
//
// Example 3:
//
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
//
// Output: true
//
// Constraints :
//
//     1 <= nums.length <= 105 - 109 <= nums[i] <= 109

class Solution {
public:
  bool containsDuplicate(const std::vector<int> &nums) {
    std::unordered_map<int, bool> hmap = {};
    for (int i = 0; i < nums.size(); i++) {
      if (hmap.count(nums.at(i)) == 1) {
        return true;
      }
      hmap.insert({nums.at(i), true});
    }
    return false;
  }
};

int main() {
  Solution sol;
  std::vector<int> vec = {1, 213, 3, 1, 4, 56, 3};
  std::cout << sol.containsDuplicate(vec) << std::endl;

  return 0;
}
