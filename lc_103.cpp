//
// Created by 12574 on 2023/9/24.
//
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

public:
    vector <vector<int>> zigzagLevelOrder(TreeNode *root) {
        queue <pair<TreeNode *, int>> q;

        if (root != nullptr) {

            q.push(make_pair(root, 0));
        }
        vector <vector<int>> results;
        while (!q.empty()) {
            auto &pair = q.front();

            TreeNode *tmp = pair.first;
            int level = pair.second;
            if (level == results.size()) {
                vector<int> new_vector;
                new_vector.push_back(root->val);
                results.push_back(new_vector);
            } else {
                results[level].push_back(root->val);
            }

            //add childs according to level
            if (level % 2 == 1) {
                if (tmp->right != nullptr) {
                    q.push(make_pair(tmp->right, level + 1));
                }
                if (tmp->left != nullptr) {
                    q.push(make_pair(tmp->left, level + 1));
                }
            } else {
                if (tmp->left != nullptr) {
                    q.push(make_pair(tmp->left, level + 1));
                }
                if (tmp->right != nullptr) {
                    q.push(make_pair(tmp->right, level + 1));
                }
            }
            q.pop();

        }
        return results;
    }
};

int main(){

}