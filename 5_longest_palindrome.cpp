#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    std::string longest;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; i - j >= 0 && i + j < n; j++) {
        if (s[i - j] != s[i + j]) {
          if ((int)longest.size() < 2 * j - 1) {
            longest = s.substr(i - j, 2 * j - 1);
          }
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; i - j + 1 >= 0 && i + j < n; j++) {
        if (s[i - j + 1] != s[i + j]) {
          if ((int)longest.size() < 2 * j - 2) {
            longest = s.substr(i - j + 1, 2 * j - 2);
          }
          break;
        }
      }
    }
    return longest;
  }
};

int main() {
  Solution sol;
  std::cout << sol.longestPalindrome("babad") << std::endl;
  std::cout << sol.longestPalindrome("cbbd") << std::endl;
}
