#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
 
unsigned long long int giliran(int tali){
    array <unsigned long long int, 40> glrn;
    glrn[0] = 1;
    glrn[1] = 1;
 
    for (int i=2; i<=tali; i++) {
        glrn[i] = 0;
        for (int j=0; j<i; j++) glrn[i] += glrn.at(j) * glrn.at(i-j-1);
    }
    return glrn[tali];
}
 
int main()
{
    int tc, tali;
    cin>>tc;
    for (int i=0; i<tc; i++){
        cin>>tali;
        if (tali == 0) cout<<0<<endl;
        else cout<<giliran(tali)<<endl;
    }
    return 0;
}