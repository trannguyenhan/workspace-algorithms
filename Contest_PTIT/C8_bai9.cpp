#include <iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

/*Y tuong : Coi nhung so la cac dinh cua mot do thi co huong, voi (E1,E2) la canh <=> E1*2 = E2 || E1-1 = E2
chay thuat toan bfs voi do thi nay de tim quang duong ngan nhat giua dinh S va T*/
/*Nhuoc diem : Co the van con kha lau voi nhung bo test co S voi T co khoang cach lon*/

int bfs(int S, int T){
    /*Do thi G voi tap E la tap cac canh*/
    /*dist(x) la khoang cach tu diem x toi diem S*/
    vector<int> dist(20000,20000);
    queue<int> q;

    /*Cai dat gia tri ban dau cho hang doi
    Ban dau hang doi chua S va dist(S) = 0 (khoang cach tu S toi chinh no bang 0)*/
    q.push(S);
    dist[S] = 0;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        /*2 canh noi voi temp lan luot la edge1, edge2*/
        int edge1 = temp*2;
        int edge2 = temp-1;

        /*for edge(u,v) thuoc E {
            if dist(v) = vc
                q.push(v);
                dist(v) = dist(u) + 1
        }*/
        /*Doan code sau tuong duong voi y tuong cua vong for tren, boi vi 1 dinh E1 bat ki chi noi voi 2 dinh
        la E1*2 va E1-1, nen thay vi chay vong for se kiem tra tung dinh thay cho vong for*/
        if(dist[edge1] == 20000){
            q.push(edge1);
            dist[edge1] = dist[temp] + 1;
        }

        if(dist[edge2] == 20000){
            q.push(edge2);
            dist[edge2] = dist[temp] + 1;
        }

        /*kiem tra neu edge1 hoac edge2 la T -> dung thuat toan va dua ra ket qua dist can tim*/
        if(edge1 == T) return dist[edge1];
        if(edge2 == T) return dist[edge2];
    }
}

int main()
{
    int botest;
    cin >> botest;
    while(botest > 0){    
    	int S, T;
    	cin >> S >> T;

    	cout << bfs(S,T);
    	cout << endl;
    	
    	botest--;
    }
}
