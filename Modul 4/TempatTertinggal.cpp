#include <iostream>
using namespace std;

int main()
{
  int t, n, m, i, j, k, l;
  
  cin >> t;
  for(i=1;i<=t;i++){
    cin >> n >> m;
    char graf[n+1][m+1];
    for(j=0;j<n;j++){
        for(k=0;k<m;k++){
            cin >> graf[j][k];
        }
    }
    
    for(k=0;k<m;k++){
        for(j=n-2;j>=0;j--){
            l=j;
            while(graf[l][k]=='*' && graf[l+1][k]=='.'){
                graf[l][k]='.';
                graf[l+1][k]='*';
                l++;
            }
        }
    }
    
    for(j=0;j<n;j++){
        for(k=0;k<m;k++){
            cout << graf[j][k];
        }
        cout << "\n";
    }
  }
}