#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// Given a list of non-negative integers nums, arrange them such that they form
// the largest number and return it.
//
// Since the result may be very large, so you need to return a string instead of
// an integer.
//
// Example 1:
//
// Input: nums = [10,2]
// Output: "210"
//
// Example 2:
//
// Input: nums = [3,30,34,5,9]
// Output: "9534330"
//
// Constraints:
//
//     1 <= nums.length <= 100
//     0 <= nums[i] <= 109

class Solution {
public:
  std::string largestNumber(std::vector<int> &nums) {
    // 1. Convert all ints to strings first to avoid repeating to_string in the
    // sort
    std::vector<std::string> strs;
    for (int n : nums)
      strs.push_back(std::to_string(n));

    // 2. Custom sort using the concatenation rule
    std::sort(strs.begin(), strs.end(),
              [](const std::string &a, const std::string &b) {
                return a + b > b + a; // The "Golden Rule" for this problem
              });

    // 3. Handle the "Leading Zeros" case
    if (strs[0] == "0")
      return "0";

    // 4. Join strings
    std::string result = "";
    for (const std::string &s : strs)
      result += s;

    return result;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums = {3, 30, 34, 5, 9};
  std::cout << sol.largestNumber(nums) << std::endl;
  nums = {10, 2};
  std::cout << sol.largestNumber(nums) << std::endl;

  return 0;
}
