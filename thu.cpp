#include<iostream.h>
#include<fstream.h>
#define MAX 256


int n,W,k,PA[MAX];

float fopt,weight=0,cost=0;

typedef struct{
    char Ten[50];
    int Trong_luong,Gia_tri;
    float Don_gia;
    // dung de sap xep gia tri cac do vat theo thu tu khong tang
    // cua c[i]/a[i]
    int Phuong_an;
} Do_vat;
Do_vat Ds_vat[MAX];

/*------------------------------------------------*/
//Lay du lieu tu file INPUT.txt :
int Lay_dulieu(){
    ifstream in("INPUT.txt");
    if (in==NULL){
        cout<<"\n  Khong tim duoc file \n";
    return 1;
    } else {
        in>>n;
        in>>W;
        k=0;
        while(k<n){
            in>>(Ds_vat[k].Ten);
            in>>(Ds_vat[k].Trong_luong);
            in>>(Ds_vat[k].Gia_tri);
            if(Ds_vat[k].Trong_luong){
                Ds_vat[k].Don_gia=float(Ds_vat[k].Gia_tri)/float(Ds_vat[k].Trong_luong);
                k++;
            }

        }

    in.close();
    return 0;
    }
}

/*------------------------------------------------------*/
//Sap xep lai danh sach do vat theo thu tu giam dan cua don gia.


void Sap_xep(){
    Do_vat temp;
    int i;
    for(i=0;i<n-1;i++)
        Ds_vat[i].Don_gia=float(Ds_vat[i].Gia_tri)/float(Ds_vat[i].Trong_luong);
    for(i=0;i<n;i++)
        for (int j=i+1;j<n ;j++){
            if(Ds_vat[i].Don_gia<Ds_vat[j].Don_gia){
                temp=Ds_vat[i];
                Ds_vat[i]=Ds_vat[j];
                Ds_vat[j]=temp;
            }
        }
}


/*----------------------------------------------*/
//Tong trong luong


void Tong_trong_luong(){
    float Tong_trong_luong =0;
    ofstream on("OUTPUT.txt",ios::app);
    for (int i=0;i<n;i++){
        Tong_trong_luong = Tong_trong_luong + Ds_vat[i].Trong_luong*Ds_vat[i].Phuong_an;
    }
    on<<"\n-Trong luong con lai cua cai tui: W = "<<W-Tong_trong_luong;
    on.close();
}

/*--------------------------------------*/
void Ket_qua(int i){
    int t=int((W-weight)/Ds_vat[i].Trong_luong);
    for(int j=t;j>=0;j--){
        PA[i] = j;
        weight = weight + Ds_vat[i].Trong_luong*PA[i];
        cost = cost + Ds_vat[i].Gia_tri*PA[i];
        if (i==n-1){
            if (cost > fopt){
                for (k=0;k<n;k++){
                    Ds_vat[k].Phuong_an = PA[k];
                    fopt = cost;
                }
            }
        } else if ((cost + Ds_vat[i+1].Gia_tri*(W-weight)/Ds_vat[i+1].Trong_luong>fopt))
            Ket_qua(i+1);

        weight = weight - Ds_vat[i].Trong_luong*PA[i];
        cost = cost - Ds_vat[i].Gia_tri*PA[i];
    }
}

/*---------------------------------------------*/
void Xuat(){
    ofstream on("OUTPUT.txt");
    for (int i =0;i<n;i++){
        on<<"*Chon "<<Ds_vat[i].Phuong_an<<" do vat loai "<<Ds_vat[i].Ten<<" \n";
        //on<<"\t\t\t\t - Gia tri vat "<<Ds_vat[i].Ten<<": v = "<<Ds_vat[i].Gia_tri_vat<<"\n\n";
    }

    on<<"\n-Gia tri toi uu la : f*="<<fopt;
    on.close();
}

//Chuong trinh chinh
int main(){
    Lay_dulieu();
    Sap_xep();
    Ket_qua(0);
    //Luu ket qua vao trong file OUTPUT
    Xuat();
    Tong_trong_luong();
    cout<<"\n\t\t\t\t * * *\n";
    cout<<"\n\t\t\t KET QUA BAI TOAN DA LUU !!! \n\n";

    return 0;
}




