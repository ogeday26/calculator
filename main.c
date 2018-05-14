//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Halil Safa Saglik || thzbr@windowslive.com
//                                                                                        ## Yazilim Notlari ##
//    >> 4 islemi yapabilmektedir.
//    >> ilk degere operatör girisi engellenmistir.
//    >> parantezler algilanabilir hale getirilmistir.
//    >> ikinci operator girisi engellenmistir.
//    >> 'B' veya 'b' tusuna basildigi takdirde ikinci menu acilir hale getirilmistir.
//    >> Son basilan tusun operator olmasi engellenmistir.
//    >> ilk degere parantez kapama son degere parantez acma engellenmistir.
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>


#define asagisag 218
#define asagisol 191
#define yukarisag 192
#define yukarisol 217
#define asagiyukarisag 195
#define asagiyukarisol 180
#define sagasolayukari 193
#define sagasolaasagi 194
#define arti 197
#define yatay 196
#define dikey 179

int bilimsel_md = 0;// hesap makinesi modunu tutar.
char islem[30]; //islemin tutuldugu dizi
int sonuc;
int dizi[30] = {{0}};//islemdeki rakamlari tutan dizi
char isaretler[20]={{0}};//islemdeki isaretleri tutan dizi
int l=0; // islemdeki toplam rakam sayisi tutan degisken
int sayi=0;
int say=0;
int c=0; //islemdeki isaretci sayisini tutan dizi
char duzenli_islem[50];


const char karakterler[16] = {{'+'},{'7'},{'4'},{'1'},{'-'},{'8'},{'5'},{'2'},{'*'},{'9'},{'6'},{'3'},{'/'},{'='},{','},{'0'}};//normal moddaki karakterler
const char bilimsel_karakterler[20] = {{'^'},{0}};//bilimsel moddaki semboller
int cursor_p(int x, int y){
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}//cursoru ilgili satir ve sutuna goturen fonksiyon




void frame(){
    int i,j,k,l,m;
    for(i=0;i<32;i++){
        cursor_p(i,0);
        printf("%c",yatay);
        cursor_p(i,4);
        printf("%c",yatay);
        cursor_p(i,8);
        printf("%c",yatay);
        cursor_p(i,12);
        printf("%c",yatay);
        cursor_p(i,16);
        printf("%c",yatay);
        cursor_p(i,20);
        printf("%c",yatay);

    }
    for(j=0;j<20;j++){
        cursor_p(0,j);
        printf("%c",dikey);
        cursor_p(32,j);
        printf("%c",dikey);
    }
    for(l=0;l<25;l+=4){
            if(l == 0){
                cursor_p(0,l);
                printf("%c",asagisag);
            }
            if(l == 4|| l == 8 || l == 12 || l == 16){
                cursor_p(0,l);
                printf("%c",asagiyukarisag);
            }
            if(l == 20){
                cursor_p(0,l);
                printf("%c",yukarisag);
            }
    }
    for(m=0;m<22;m+=4){
        if(m == 0){
            cursor_p(32,m);
            printf("%c",asagisol);
        }
        if(m == 20){
            cursor_p(32,m);
            printf("%c",yukarisol);
        }
        if(m == 4 || m == 8 || m == 12 || m == 16){
            cursor_p(32,m);
            printf("%c",asagiyukarisol);
        }
    }
    for(k=5;k<20;k++){
        cursor_p(8,k);
        printf("%c",dikey);
        cursor_p(16,k);
        printf("%c",dikey);
        cursor_p(24,k);
        printf("%c",dikey);
    }
    for(i=8;i<=24;i+=8){
        cursor_p(i,4);
        printf("%c",sagasolaasagi);
        cursor_p(i,20);
        printf("%c",sagasolayukari);
    }
    for(i=8;i<=24;i+=8){
        for(j=8;j<=16;j+=4){
            cursor_p(i,j);
            printf("%c",arti);
        }
    }
    k=0;
    for(i=4;i<=28;i+=8){
        for(j=6;j<=20;j+=4){
            cursor_p(i,j);
            printf("%c",karakterler[k]);
            k++;
        }
    }
    cursor_p(5,22);
    printf("Bilimsel Hesap modunu acmak ve kapatmak icin #b# tusuna basiniz.");
}//ana ekranin ciktisini veren fonksiyon

void bilimsel_frm(){
    int i,j,k=0;
    for(i=34;i<=65;i++){
        cursor_p(i,0);
        printf("%c",yatay);
        cursor_p(i,20);
        printf("%c",yatay);
        cursor_p(i,16);
        printf("%c",yatay);
        cursor_p(i,12);
        printf("%c",yatay);
        cursor_p(i,8);
        printf("%c",yatay);
        cursor_p(i,4);
        printf("%c",yatay);
        if(i == 65)
        {
            cursor_p(65,0);
            printf("%c",asagisol);
            cursor_p(65,20);
            printf("%c",yukarisol);
        }
    }

    for(i=1;i<20;i++){
        cursor_p(33,i);
        printf("%c",dikey);
        cursor_p(65,i);
        printf("%c",dikey);
        cursor_p(41,i);
        printf("%c",dikey);
        cursor_p(49,i);
        printf("%c",dikey);
        cursor_p(57,i);
        printf("%c",dikey);
        if(i == 19)
        {
            cursor_p(33,0);
            printf("%c",asagisag);
            cursor_p(33,20);
            printf("%c",yukarisag);
            Sleep(1);
        }
    }

    for(i=41;i<=57;i+=8){
        cursor_p(i,0);
        printf("%c",sagasolaasagi);
        cursor_p(i,20);
        printf("%c",sagasolayukari);
        Sleep(1);
    }

    for(i=41;i<=57;i+=8){
        for(j=4;j<20;j+=4){
            cursor_p(i,j);
            printf("%c",arti);
            Sleep(1);
        }
    }

    for(i=4;i<20;i+=4){
        cursor_p(33,i);
        printf("%c",asagiyukarisag);
        cursor_p(65,i);
        printf("%c",asagiyukarisol);
        Sleep(1);
    }


    for(i=37;i<=65;i+=8){
        for(j=2;j<=20;j+=4){
            cursor_p(i,j);
            printf("%c",bilimsel_karakterler[k]);
            k++;
            Sleep(1);
            }
        }

}//bilimsel mod ekraninin ciktisini veren fonksiyon

void bilimsel_frm_cls(){
    int i,j;
    for(i=33;i<=65;i++){
        for(j=0;j<=20;j++){
            cursor_p(i,j);
            printf(" ");
            Sleep(1);
        }
    }

}//bilimsel mod ekranini silen fonksiyon

void islem_alma(){
    int k=0,i,j,m=1;
    int parantez = 0;
    char x;
    cursor_p(1,1);
    while(m != 30){
        m++;
        x = getche();
        if(x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9' || x == '0' || x == '+' || x == '-' || x == '*' || x == '/' || x == 13 || x =='b' || x == 'B' || x == 8 || x == '^' || x == '(' || x == ')'){
            islem[k] = x;
            k++;
            if(islem[k-1] == '('){
                parantez++;
            }
            if(islem[k-1] == ')'){
                parantez--;
            }
            if(x != 0 && k == 1){
                for(j=1;j<30;j++){
                    cursor_p(j,1);
                    printf(" ");
                    cursor_p(j,2);
                    printf(" ");
                }
                cursor_p(1,1);
                printf("%c",x);
                cursor_p(2,1);
            }
            if(islem[k-1] == '+' || islem[k-1] == '-' || islem[k-1] == '*' || islem[k-1] == '/' || islem[k-1] == '^'){
                if(islem[k-2] == '+' || islem[k-2] == '-' || islem[k-2] == '*' || islem[k-2] == '/' || islem[k-2] == '^'){
                    printf("%c",8);
                    k--;
                }
            }
            if(k == 1){
                if(islem[k-1] == '+' || islem[k-1] == '-' || islem[k-1] == '*' || islem[k-1] == '/' || islem[k-1] == '^' || islem[k-1] == ')'){
                    printf("%c",8);
                    k--;
                }
            }
            if(x == 'b' || x == 'B'){
                if(bilimsel_md == 0){
                    bilimsel_md+=1;
                    bilimsel_frm();//bilimsel ekrani acma
                    for(j=1;j<30;j++){
                        cursor_p(j,1);
                        printf(" ");
                        cursor_p(j,2);
                        printf(" ");

                    }
                cursor_p(1,1);
                m=1;
                }else{
                    bilimsel_md-=1;
                    bilimsel_frm();
                    bilimsel_frm_cls();//bilimsel ekrani kapatma
                    for(j=1;j<30;j++){
                        cursor_p(j,1);
                        printf(" ");
                        cursor_p(j,2);
                        printf(" ");
                    }
                cursor_p(1,1);
                m=1;
                }
            }
            if(x == 30){
                break;
            }
            if(islem[k-1] == 13){
                if(islem[k-2] == '+' || islem[k-2] == '-' || islem[k-2] == '*' || islem[k-2] == '/' || islem[k-2] == '^' || islem[k-2] == '('){
                    printf("%c",8);
                    printf("%c",8);
                    k--;
                    islem[k-1] = 13;
                }
                for(i=k;i<30;i++){
                    islem[i] = 0;
                    k++;
                }
                if(k == 30 && parantez == 0){
                    break;
                }


            }
        }else{
            printf("%c",8);
        }
    }
}//islemi alan fonksiyon ayni zamanda anahtarlama gorevi yapar

void islem_parcalama(){
    int k=0;
    l=0;
    while(islem[k] != 0){
        if(islem[k] == 47 || islem[k] == 42 || islem[k] == 45 || islem[k] == 43 || islem[k] == 13 ||  islem[k] == 94){
            dizi[l]=say;
            say=0;
            sayi=0;
            l++;

            switch(islem[k]){
            case 43:
                isaretler[c] = 43;
                c++;
                break;
            case 45:
                isaretler[c] = 45;
                c++;
                break;
            case 42:
                isaretler[c] = 42;
                c++;
                break;
            case 47:
                isaretler[c] = 47;
                c++;
                break;
            case 94:
                isaretler[c] = 94;
                c++;
                break;
            }
            k++;

        }else{
            switch(islem[k]){
                case '0':
                    sayi = 0;
                    break;
                case '1':
                    sayi = 1;
                    break;
                case '2':
                    sayi = 2;
                    break;
                case '3':
                    sayi = 3;
                    break;
                case '4':
                    sayi = 4;
                    break;
                case '5':
                    sayi = 5;
                    break;
                case '6':
                    sayi = 6;
                    break;
                case '7':
                    sayi = 7;
                    break;
                case '8':
                    sayi = 8;
                    break;
                case '9':
                    sayi = 9;
                    break;
            }
            say*=10;
            say+=sayi;
            sayi=0;
            k++;

        }
    }
}//sayilar ve isaretleri ilgili dizilere ayiklayan fonksiyon

void carpma_bolme(){
    int k=0,i = 0,j;
    while(l != 1  && k != c){
            if(isaretler[k] == '+' || isaretler[k] == '-'){
                    k++;
            }
            else if(isaretler[k] == '*'){
                sonuc=dizi[k]*dizi[k+1];
                dizi[k]=sonuc;
                for(j=k;j<c;j++){
                    isaretler[j]=isaretler[j+1];
                }
                for(j=k+1;j<l;j++){
                    dizi[j]=dizi[j+1];
                }
                sonuc=0;
                l--;
                c--;
            }else if(isaretler[k] == '/'){
                sonuc=dizi[k]/dizi[k+1];
                dizi[k]=sonuc;
                for(j=k;j<c;j++){
                    isaretler[j]=isaretler[j+1];
                }
                for(j=k+1;j<l;j++){
                    dizi[j]=dizi[j+1];
                }
                sonuc=0;
                l--;
                c--;
            }
    }
}//carpma ve bolme islemini yapan fonksiyon

void toplama_cikarma(){
    int k=0,j;
    while(l != 1){
        if(isaretler[k] == '+'){
                sonuc=dizi[k]+dizi[k+1];
                dizi[k]=sonuc;
                for(j=k;j<c;j++){
                    isaretler[j]=isaretler[j+1];
                }
                for(j=k+1;j<l;j++){
                    dizi[j]=dizi[j+1];
                }
                sonuc=0;
                l--;
                c--;
            }else if(isaretler[k] == '-'){
                sonuc=dizi[k]-dizi[k+1];
                dizi[k]=sonuc;
                for(j=k;j<c;j++){
                    isaretler[j]=isaretler[j+1];
                }
                for(j=k+1;j<l;j++){
                    dizi[j]=dizi[j+1];
                }
                sonuc=0;
                l--;
                c--;
            }
    }
}//toplama ve cikarma islemlerini yapan fonksiyon


void cikti(){
    int j;
    for(j=1;j<30;j++){
        cursor_p(j,2);
        printf(" ");
    }
    cursor_p(1,2);
    printf("%d",dizi[0]);
    cursor_p(1,1);
}//sonucu veren fonksiyon

void uslu_sayi(){
    int k=0,i = 0,j;
    while(l != 1  && k != c){
        if(isaretler[k] == '^' ){
            sonuc=1;
            for(i=1;i<=dizi[k+1];i++){
                sonuc*=dizi[k];
            }
            dizi[k]=sonuc;
            for(j=k;j<c;j++){
                isaretler[j]=isaretler[j+1];
            }
            for(j=k+1;j<l;j++){
                   dizi[j]=dizi[j+1];
            }
            sonuc=1;
            l--;
            c--;
        }else{
            k++;
        }
    }
    sonuc=0;
}//ust alan fonksiyon

int main(){

    frame();
    while(1){
        islem_alma();
        islem_parcalama();
        if(c == 0){
            cursor_p(1,1);
            printf("error");
        }
        uslu_sayi();
        carpma_bolme();
        toplama_cikarma();
        cikti();
    }


    return 0;
}
