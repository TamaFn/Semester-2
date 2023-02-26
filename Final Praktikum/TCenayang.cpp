#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define a first
#define b second

int main() {
    int n;
    cin >> n;
    int min_area = INT_MAX;
    pair<ll, ll> p[n];
    for(int i=0; i<n;i++){
        cin >>p[i].first>>p[i].second;
    }
    int sama = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++){
            for(int k=j+1;k<n;k++){
                int x = (p[i].a*p[j].b+p[j].a*p[k].b+p[k].a*p[i].b);
                int y = (p[i].b*p[j].a+p[j].b*p[k].a+p[k].b*p[i].a);
                int area = abs(x-y);
                
                if(area!=0){
                    if(area== min_area){
                        sama = min_area;
                    }else{
                        min_area=min(min_area, area);
                    }
                }
            }
        }
    }
    if(sama == min_area||min_area==INT_MAX){
        cout<<"-1.00"<<endl;
    }else{
        printf("%.2lf\n", double(min_area)/2);
    }
    return 0;
}