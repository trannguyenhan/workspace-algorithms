/*
  -------------------------------------------------------------------------------------------------------
  |  ios::app	|    Chế độ Append. Tất cả output tới file đó được phụ thêm vào cuối file đó            |
  -------------------------------------------------------------------------------------------------------
  |  ios::ate	|    Mở một file cho outpur và di chuyển điều khiển read/write tới cuối của file        |
  -------------------------------------------------------------------------------------------------------
  |  ios::in	|    Mở một file để đọc                                                                 |
  -------------------------------------------------------------------------------------------------------
  |  ios::out	|    Mở một file để ghi                                                                 |
  -------------------------------------------------------------------------------------------------------
  |  ios::trunc	|    Nếu file này đã tồn tại, nội dung của nó sẽ được cắt (truncate) trước khi mở file  |
  -------------------------------------------------------------------------------------------------------

  void open(const char *ten_file, ios::che_do);
*/
#include<bits/stdc++.h>
using namespace std;

void write_file(string data){
    ofstream ofile;
    ofile.open("result.txt");

    ofile << data << endl;

    ofile.close();
}

void read_file_1(){
    ifstream ifile;
    ifile.open("result.txt");

    string line;
    while(!ifile.eof()){
        getline(ifile, line);
        cout << line << endl;
    }

    ifile.close();
}

void read_file_2(){
    ifstream ifile;
    ifile.open("result.txt");

    string data;
    while(!ifile.eof()){
        ifile >> data;
        cout << data << endl;
    }

    ifile.close();
}

int main(){
    write_file("Hello world world!");
    read_file_2();
    return 0;
}
