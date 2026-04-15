#include <vector>
// 66. Plus One
//
// You are given a large integer represented as an integer array digits, where
// each digits[i] is the ith digit of the integer. The digits are ordered from
// most significant to least significant in left-to-right order. The large
// integer does not contain any leading 0's.
//
// Increment the large integer by one and return the resulting array of digits.

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int n = digits.size() - 1;
    digits[n]++;
    while (digits.at(n) > 9) {
      digits[n] = 0;
      n--;
      if (n < 0) {
        digits.insert(digits.begin(), 1);
        break;
      } else {
        digits[n]++;
      }
    }
    return digits;
  }
};

