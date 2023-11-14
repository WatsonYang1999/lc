//
// Created by 12574 on 2023/2/15.
//
#include<iostream>
#include<queue>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q_n;
        queue<int> q_l;
        vector<vector<int>> result;
        if (root != nullptr) {
            q_n.push(root);
            q_l.push(0);
        }
        while (!q_n.empty()) {
            TreeNode *head = q_n.front();
            q_n.pop();
            int level = q_l.front();
            q_l.pop();

            if (level >= result.size()) {
                vector<int> new_arr;
                new_arr.push_back(head->val);
                result.push_back(new_arr);
            } else {
                result[level].push_back(head->val);
            }
            if(head->left!= nullptr){
                q_n.push(head->left);
                q_l.push(level+1);
            }
            if(head->right!= nullptr){
                q_n.push(head->right);
                q_l.push(level+1);
            }

        }
        return result;
    }
};

int main() {

}