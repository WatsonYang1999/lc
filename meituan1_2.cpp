#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    string ss = string(s);
    string tt = string(t);
    vector<char> v1, v2;
    set<char> set1, set2;
    int common_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            v1.push_back(s[i]);
            v2.push_back(t[i]);
            set1.insert(s[i]);
            set2.insert(t[i]);

        } else {
            common_count++;
        }
    }
    bool f1 = false, f2 = false;
    for(int i = 0;i<v1.size();i++) {
        for(int j = 0; j < v1.size();j++){
            if(v1[i] == v2[j]) {
                f1 = true;
                if(v1[j] == v2[i]) {
                    f2 = true;
                }
            }
        }
        if (f2) break;
    }
    if(f2) cout << common_count + 2 <<endl;
    else {
        if(f1) cout << common_count + 1 <<endl;
        else cout << common_count << endl;
    }
    return 0;
}
