#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
// Given a pattern and a string s, find if s follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a
// letter in pattern and a non-empty word in s. Specifically:
//
//     Each letter in pattern maps to exactly one unique word in s.
//     Each unique word in s maps to exactly one letter in pattern.
//     No two letters map to the same word, and no two words map to the same
//     letter.
//
// Example 1:
//
// Input: pattern = "abba", s = "dog cat cat dog"
//
// Output: true
//
// Explanation:
//
// The bijection can be established as:
//
//     'a' maps to "dog".
//     'b' maps to "cat".
//
// Example 2:
//
// Input: pattern = "abba", s = "dog cat cat fish"
//
// Output: false
//
// Example 3:
//
// Input: pattern = "aaaa", s = "dog cat cat dog"
//
// Output: false
//
// Constraints:
//
//     1 <= pattern.length <= 300
//     pattern contains only lower-case English letters.
//     1 <= s.length <= 3000
//     s contains only lowercase English letters and spaces ' '.
//     s does not contain any leading or trailing spaces.
//     All the words in s are separated by a single space.

class Solution {
public:
  bool wordPattern(std::string pattern, std::string s) {
    std::unordered_map<std::string, char> map;
    std::unordered_map<char, std::string> map_inv;
    std::istringstream iss(s);
    std::string word;
    int i = 0;
    while (iss >> word) {
      if (i >= pattern.length())
        return false;
      if (map.count(word)) {
        if (map.at(word) != pattern.at(i))
          return false;
      } else if (map_inv.count(pattern.at(i))) {
        if (map_inv.at(pattern.at(i)) != word)
          return false;
      } else {
        map.insert({word, pattern.at(i)});
        map_inv.insert({pattern.at(i), word});
      }
      i++;
    }
    return i == pattern.length();
  }
};
int main() {
  Solution sol;
  std::string pattern = "abba";
  std::string s = "dog cat cat dog";
  std::cout << sol.wordPattern(pattern, s) << std::endl;

  return 0;
}
