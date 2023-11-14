#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
float distance(float x,float y ,float z){
    return x*x+y*y+z*z;
}

class Point{
private:
    float x,y,z;

public:
    Point(float x,float y,float z):x(x),y(y),z(z){}
    bool operator<(const Point &p)const{
        return distance(x,y,z)< distance(p.x,p.y,p.z);
    }
    friend ostream & operator<<(ostream& os,const Point &p){
        os<<"("<<p.x<<","<<p.y<<","<<p.z<<")";
        return os;
    }
    string to_string() const{
        string s = "("+std::to_string(x)+","+std::to_string(y)+","+std::to_string(z)+")";
        return s;
    }
};

int main(){
    priority_queue<Point> pq;
    unordered_map<string,int> s_map;
    s_map.insert({"Alice",5});
    s_map.insert({"Bob",3});
    for(auto it = s_map.begin();it!=s_map.end();it++){
        if(it->first=="Alice") it->second = 1000;
    }
    cout << s_map["Alice"]<<endl;

}