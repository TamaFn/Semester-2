#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ullu;
int main(){
    ullu angka;
    set<ullu> s;
	while(scanf("%llu",&angka)!=EOF){
        if(s.count(angka)){
                int x = angka%10001;
                int ans = ????; //CARI ANS-NYA!!!
                if(x < ans) printf("<\n");
                if(x ==ans) printf("==\n");
                if(x > ans) printf(">\n");
        }else s.insert(angka);
    }

	return 0;
}