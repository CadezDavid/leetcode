#include <iostream>
#include <vector>

struct Rectangle {
  int begin;
  int end;
  int height;
  int volume;
};

struct Pair {
  int height;
  int index;
};

int first_larger(const std::vector<Pair> &blockers, int target) {
  if (blockers.empty())
    return 0;

  std::cout << "Calculating first_larger for: ";
  for (Pair blocker : blockers) {
    std::cout << "{" << blocker.height << ", " << blocker.index << "},";
  }
  std::cout << " and target: ";
  std::cout << target;
  std::cout << std::endl;

  int left = 0;
  int right = blockers.size();
  int middle = 0;
  while (left + 1 != right) {
    middle = (left + right) / 2;
    if (blockers.at(middle).height < target) {
      left = middle;
    } else {
      right = middle;
    }
  }
  std::cout << "First larger (or eq) at: " << middle << std::endl;
  return right;
}

Rectangle largest_rectangle(const std::vector<int> &blocks) {
  std::vector<Pair> blockers{{0, -1}};

  Rectangle largest{0, 0, 0, 0};
  int target;
  int curr_h;
  for (int i = 0; i <= blocks.size(); i++) {
    curr_h = (i == blocks.size()) ? 0 : blocks[i];
    if (blockers.back().height < curr_h) {
      std::cout << "New block is larger, so moving forward." << std::endl;
      blockers.push_back({curr_h, i});
      std::cout << "New blockers: ";
      for (auto item : blockers)
        std::cout << "{" << item.height << ", " << item.index << "}, ";
      std::cout << std::endl << std::endl;
    } else if (blockers.back().height > curr_h) {
      std::cout << "New block is strictly smaller. ";
      target = first_larger(blockers, curr_h);
      // 1. check for largest
      for (int j = target; j < blockers.size(); j++) {
        if (largest.volume <
            blockers.at(j).height * (i - blockers.at(j).index)) {
          std::cout << "Found new largest: ";
          largest = {blockers.at(j).index, i - 1, blockers.at(j).height,
                     blockers.at(j).height * (i - blockers.at(j).index)};
          std::cout << "begin: " << largest.begin << ", end: " << largest.end
                    << ", height: " << largest.height
                    << ", volume: " << largest.volume;
          std::cout << std::endl;
        }
      }
      // 2. pop blockers and insert one new one
      std::cout << "Erasing the rest of blockers (from " << target
                << " to the end)" << std::endl;
      blockers.erase(blockers.begin() + target, blockers.end());
      blockers.push_back({curr_h, blockers.back().index + 1});
      std::cout << "Added {" << curr_h << ", " << blockers.back().index
                << "} to blockers." << std::endl
                << std::endl;
    } else {
      std::cout << "New block is exactly the same, so ignoring." << std::endl
                << std::endl;
    }
  }

  return largest;
}
int main() {
  std::vector<int> blocks{1, 2, 3, 4, 5};
  Rectangle largest = largest_rectangle(blocks);
  std::cout << "begin: " << largest.begin << ", end: " << largest.end
            << ", height: " << largest.height << ", volume: " << largest.volume;
  std::cout << std::endl;
  return 0;
}
