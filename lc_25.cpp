//
// Created by 12574 on 2023/10/13.
//
#include <iostream>
#include <deque>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution25 {
public:
    static ListNode* reverseKGroup(ListNode* head, int k) {
        deque<ListNode*> dq;
        int n = 0;
        ListNode* result = new ListNode(0);
        ListNode* current = result;
        ListNode* tail = current;
        while(head){

            dq.push_back(head);
            head = head->next;
            n++;

            if(n==k) {

                while(!dq.empty()) {
                    cout<< dq.back()<<endl;
                    ListNode *node = dq.back();
                    node->next = nullptr;
                    current->next = node;
                    current = current->next;
                    dq.pop_back();
                    tail = current;
                }
                n=0;
            }
        }

        while(!dq.empty()){
            ListNode *node = dq.front();
            node->next = nullptr;
            current->next = node;
            current = current->next;
            dq.pop_front();

        }

        return result->next;
    }
};
void printList(ListNode *head){
    while (head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode* createList(vector<int>& v){
    ListNode *head = new ListNode(0);
    ListNode* current = head;
    for(auto &i:v){

        current->next = new ListNode(i, nullptr);
        current = current->next;
    }

    return head->next;
}
int main() {
    vector<int> v = {1,2,3,4,5,6,7,8};
    ListNode* list1 = createList(v);

    printList(list1);
    auto solution = Solution25();
    printList(solution.reverseKGroup(list1,2));

}