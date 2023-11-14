#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    bool search(vector<vector<int>>& matrix, int x1,int y1,int x2 ,int y2,int target){

        if(x1==x2){
            for(int i=y1;i<=y2;i++)
                if (matrix[x1][i]==target) return true;
            return false;
        }

        if(y1==y2){
            printf("Here\n");
            for(int i=x1;i<=x2;i++)
            {

                cout<<i<<y1<<endl;
                if (matrix[i][y1]==target) return true;
            }
            return false;
        }
        int v = matrix[x1][y2];
        if(v==target) return true;
        else if(v>target){
            return search(matrix,x1,y1,x2,y2-1,target);
        }
        else{
            return search(matrix,x1+1,y1,x2,y2,target);
        }
    }
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x1=0,y1=0;
        int x2 = matrix[0].size()-1;
        int y2 = matrix.size()-1;
        cout<<x1<<y1<<x2<<y2<<endl;
        return search(matrix,x1,y1,x2,y2,target);

    }
};
using  namespace  std;
int main(){
//    vector<vector<int>> matrix = {
//            {1,4,7,11,15},
//            {2,5,8,12,19},
//            {3,6,9,16,22},
//            {10,13,14,17,24},
//            {18,21,23,26,30}};
    vector<vector<int>> matrix = {{1,1}};
    Solution* ptr = new Solution();
    cout<<ptr->searchMatrix(matrix,0);
}