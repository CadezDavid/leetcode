#include <queue>
#include <vector>

// You are given an array of k linked-lists lists, each linked-list is sorted in
// ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.
//
//
//
// Example 1:
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6
//
// Example 2:
//
// Input: lists = []
// Output: []
//
// Example 3:
//
// Input: lists = [[]]
// Output: []

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    ListNode *merged = new ListNode();
    ListNode *head = merged;
    auto cmp = [](ListNode *a, ListNode *b) {
      return a->val > b->val; // > makes it a min-heap
    };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)>
        firsts(cmp);

    for (ListNode *first : lists) {
      if (first != nullptr)
        firsts.push(first);
    }

    while (!firsts.empty()) {
      head->next = firsts.top();
      head = head->next;
      ListNode *tmp = firsts.top()->next;
      firsts.pop();
      if (tmp != nullptr) {
        firsts.push(tmp);
      }
      head->next = nullptr;
    }
    return merged->next;
  }
};
