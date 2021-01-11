#include<bits/stdc++.h>
using namespace std;

int *dictionary;
void dem(string str){
    dictionary = new int(150);
    int lens = str.length();
    for(int i=0; i<lens; i++){
        dictionary[str[i]]++;
    }
}

struct HocSinh{
    char *name;
    float gpa;
};
void changeName(HocSinh &b){
    if(b.name[0] >= 'A' && b.name[0] <= 'Z'){
        b.name[0] = b.name[0] - ('A' - 'a');
    }
}

int search_b4(char a[], char key, int n){
    int size_b4 = strlen(a);
    a[size_b4] = key;
    a[size_b4 + 1] = '\0';

    int pos = 0;
    while(a[pos] != key) pos++;

    int tim;
    if(pos >= size_b4) tim = 0;
    else tim = 1;

    return tim;
}

struct Book{
    char* id;
    char *name;
    int totalPage;
}

int main(){
    /*------------Cau 1------------*/
    //dem("Nguyen Quang HuyN");
    //cout << dictionary['N'];

    /*------------Cau 2------------

        int A[100] : Khai báo mảng tĩnh, không thể thay đổi kích thước sau khi khai báo.
        int *A = (int*) malloc(sizeof(int) * 100) : khai báo mảng động, có thể thay đổi kích thước sau khi khai báo.
    */

    /*------------Cau 3------------*/
    //char *c = "Nguyen Van A";
    //struct HocSinh hs;
    //hs.name = c;
    //changeName(hs);

    //cout << hs.name << endl;


    /*------------Cau 3------------
        Đoạn code dưới sai ở phần khai báo con trỏ ptr, nếu khai báo như vậy thì ptr là hằng và không thể thay đổi nó (ptr chỉ đọc).
        Sửa : bỏ const trong khai báo ptr
    */
    //int i = 10;
    //int j = 20;
    //const int *ptr = &i;
    //printf("ptr : %d\n", *ptr);
    //*ptr = 100;
    //ptr = &j;
    //printf("ptr : %d\n", *ptr);

    /*------------Cau 4------------
	Tối ưu : Dùng lính canh, đặt key ở cuối, bỏ đi 1 thao tác so sánh pos < size
    */
    char a[100] = "nguyen quang huy";
    cout << search_b4(a, 'y', 16);

    /*------------Cau 5------------
	Tối ưu : Dùng lính canh, đặt key ở cuối, bỏ đi 1 thao tác so sánh pos < size
    */
    return 0;
}
