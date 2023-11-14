//
// Created by 12574 on 2023/9/24.
//
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set <ListNode*> vis;
        for (ListNode *current = headA; current != nullptr; current = current->next) {
            vis.insert(current);
        }

        for (ListNode *current = headB; current != nullptr; current = current->next) {
            if (vis.find(current) != vis.end()) {
                return current;
            }
        }
        return nullptr;
    }
};