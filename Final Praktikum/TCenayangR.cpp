#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define e first
#define f second

using namespace std;

int main() {
    int N;
    cin >> N;
    int minimal_area = INT_MAX;
    pair<ll, ll> p[N];
    for(int i=0; i<N; i++){
        cin >> p[i].first >> p[i].second;
    }
    int same = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int z=j+1; z<N; z++){
                int x = (p[i].e*p[j].f+p[j].e*p[z].f+p[z].e*p[i].f);
                int y = (p[i].f*p[j].e+p[j].f*p[z].e+p[z].f*p[i].e);
                int area = abs(x-y);
                
                if(area != 0){
                    if(area == minimal_area){
                        same = minimal_area;
                    }
                    else{
                        minimal_area=min(minimal_area, area);
                    }
                }
            }
        }
    }
    if(same == minimal_area || minimal_area == INT_MAX){
        cout << "-1.00" << endl;
    }
    else{
        printf("%.2lf\n", double(minimal_area)/2);
    }
    return 0;
}
