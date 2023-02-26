#include <stdio.h>

void inisialisasi();
void baca();
void apakahPrima(int bilangan);
void masukPrima(int bilangan);
void bukanPrima(int bilangan);
void tampilStack();

typedef struct STACK{
    int topPrim;
    int topNonPrim;
    int prima[1000];
    int non[1000];
} STACK;
STACK ikki;

int main(){
    baca();
    tampilStack();
    return 0;
}

void inisialisasi(){
    ikki.topPrim = -1;
    ikki.topNonPrim = -1;
}

void baca(){
    int i;
    int jumlah; //jumlah bilangan ikki
    int bilangan;
    scanf("%d", &jumlah);
    for (i=0; i<jumlah; i++){
        scanf("%d", &bilangan);
        apakahPrima(bilangan);    
    }
}

void apakahPrima(int bilangan){
    int i, flag = 0;
    if (bilangan == 0 || bilangan == 1) flag = 1;
    for (i=2; i<=bilangan/2; ++i) {
        if (bilangan%i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) masukPrima(bilangan);
    else bukanPrima(bilangan);
}

void masukPrima(int bilangan){
    ikki.prima[++ikki.topPrim] = bilangan;
}

void bukanPrima(int bilangan){
    ikki.non[++ikki.topNonPrim] = bilangan;
}

void tampilStack(){
    int i;
    for(i=ikki.topPrim; i>0; i--) printf("%d\n", ikki.prima[i]);
    for(i=ikki.topNonPrim; i>0; i--) printf("%d\n", ikki.non[i]);
}