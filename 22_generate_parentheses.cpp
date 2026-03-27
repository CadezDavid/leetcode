#include <string>
#include <vector>

// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// Example 1:
//
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
//
// Example 2:
//
// Input: n = 1
// Output: ["()"]

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    if (n == 0) {
      return {""};
    }
    std::vector<std::string> combs = {};
    for (int i = 0; i < n; i++) {
      std::vector<std::string> inner = generateParenthesis(i);
      std::vector<std::string> outer = generateParenthesis(n - i - 1);
      for (std::string string_inner : inner) {
        for (std::string string_outer : outer) {
          combs.push_back("(" + string_inner + ")" + string_outer);
        }
      }
    }
    return combs;
  }
};
