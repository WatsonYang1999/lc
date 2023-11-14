//
// Created by 12574 on 2023/10/25.
//
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class CustomObject{
private:
    int priority;
    int age;
    string name;
public:
    CustomObject(int age,string name):age(age),name(name){

    }

    bool operator<(const CustomObject& other) const {
        return priority < other.priority;
    }


};

int main(){

}
[[".",".",".",".",".",".","5",".","."],
 [".",".",".",".",".",".",".",".","."],
 [".",".",".",".",".",".",".",".","3"],
 [".","2",".","7",".",".",".",".","."],
 ["8","3","6","5",".",".",".",".","1"],
 [".",".",".",".",".","1",".",".","."],
 ["2",".",".",".",".",".",".",".","5"],
 [".",".",".",".",".",".",".",".","7"],
 [".",".",".","4",".",".",".","7","."]]