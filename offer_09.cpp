//
// Created by 12574 on 2023/2/11.
//
#include <iostream>
#include <stack>
using namespace  std;
class CQueue{
private:
    stack<int> inStack,outStack;

public:
    CQueue(){

    }
    void appendTail(int value){
        inStack.push(value);
    }

    int deleteHead(){
        if (outStack.empty()){
            if(inStack.empty()) {
                return -1;
            }
            while(!inStack.empty()){
                int tmp = inStack.top();
                inStack.pop();
                outStack.push(tmp);
            }
        }
        int value = outStack.top();
        outStack.pop();
        return value;
    }
};
int main(){

}