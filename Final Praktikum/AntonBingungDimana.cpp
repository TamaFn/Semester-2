#include <iostream>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

int main() {
    deque<string> jalan;
    jalan.push_back("home");
    jalan.push_back("anton");
    int N;
    cin >> N;
    while (N){
        string input;
        string str;
        cin >> input;
        if(input.compare("goto") == 0){
            cin >> str;
            jalan.push_back(str);
        } else if (input.compare("whereami") == 0){
            if(jalan.size() != 0){
                for (auto i = jalan.begin(); i != jalan.end(); i++){
                    cout << ' '<< *i;
                    if (*i != jalan.back()){
                        cout << "/";
                    }  
                cout << endl;
                }
            } else {
                cout << "i am nowhere" << endl;
            }
        } else if (input.compare("goback") == 0) {
            if (jalan.size() != -0)
                jalan.pop_back();
            else cout << "cannot go back" << endl;
        } else {
            cout << "Query not found" << endl;
        }
    }
    

}