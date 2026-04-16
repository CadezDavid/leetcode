#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
// A phrase is a palindrome if, after converting all uppercase letters into
// lowercase letters and removing all non-alphanumeric characters, it reads the
// same forward and backward. Alphanumeric characters include letters and
// numbers.
//
// Given a string s, return true if it is a palindrome, or false otherwise.
//
//
//
// Example 1:
//
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
//
// Example 2:
//
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
//
// Example 3:
//
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric
// characters. Since an empty string reads the same forward and backward, it is
// a palindrome.
//
//
//
// Constraints:
//
//     1 <= s.length <= 2 * 105
//     s consists only of printable ASCII characters.
class Solution {
public:
  bool isPalindrome(std::string s) {
    if (s.empty())
      return true;

    s.erase(std::remove_if(s.begin(), s.end(),
                           [](unsigned char c) { return !std::isalnum(c); }),
            s.end());
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    int i = 0;
    while (2 * i + 1 < s.size()) {
      if (s.at(i) != s.at(s.size() - i - 1))
        return false;
      i++;
    }
    return true;
  }
};

int main() {
  Solution sol;
  std::string s = "race a car";
  std::cout << sol.isPalindrome(s) << std::endl;
  s = "A man, a plan, a canal: Panama";
  std::cout << sol.isPalindrome(s) << std::endl;

  return 0;
}
