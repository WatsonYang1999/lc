#include <iostream>
#include <deque>
#include <vector>
#include <queue>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* insertTail(ListNode*tail,ListNode* node){
        tail->next = node;
        tail = tail->next;
        return tail;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> q1,q2;

        ListNode *current = head;
        while(current){
            if(current->val < x){
                q1.push(current);
            }
            else{
                q2.push(current);
            }
            current  =current->next;
        }

        ListNode* new_head = new ListNode(0);
        ListNode* tail = new_head;
        while(!q1.empty()){
            tail = insertTail(tail,q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            tail = insertTail(tail,q2.front());
            q2.pop();
        }
        return new_head->next;
    }
};