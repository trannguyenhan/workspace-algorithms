#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000;

// Binh nuoc co luong nuoc hien tai la luongnuoc, va chua duoc toi da dungtich lit nuoc
struct binhNuoc{
    int luongnuoc;
    int dungtich;
};
binhNuoc binhA, binhB;
int c;

// input data
void inputData(){
    int a,b;
    cin >> a >> b >> c;
    binhA.dungtich = a;
    binhB.dungtich = b;
}

// Co 2 cach do nuoc :
// C1 : do tu binh nay sang binh kia ( neu binh co chua nuoc)
// C2 : do tu be vao ( neu do tu be vao thi chi co do day binh)
// C3 : do tu binh vao be ( do tu binh vao be thi binh do het)
// Th1 : do nuoc tu be vao mot binh
void pourWater(binhNuoc &binh){
    binh.luongnuoc = binh.dungtich;
}

// Th2 : do tu binh A vao binh B
void pourWater(binhNuoc &binh1, binhNuoc &binh2){
    if(binh1.luongnuoc + binh2.luongnuoc < binh2.dungtich){
        binh2.luongnuoc = binh1.luongnuoc + binh2.luongnuoc;
        binh1.luongnuoc = 0;
        return;
    } else {
        binh1.luongnuoc = binh1.luongnuoc + binh2.luongnuoc - binh2.dungtich;
        binh2.luongnuoc = binh2.dungtich;
        return;
    }
}

// Them 1 tham so nua de xac dinh va binh nay do vao be
void pourWater(binhNuoc &binh, bool dovaobe){
    binh.luongnuoc = 0;
}

// Kiem tra dieu kien de bai
// Neu co 1 trong 2 binh co c lit nuoc -> true
bool checkStop(binhNuoc binh1, binhNuoc binh2){
    if(binh1.luongnuoc == c || binh2.luongnuoc == c)
        return true;
    else return false;
}

queue<pair<int,int> > Q;
// Danh dau lai vi tri da di qua
// Vi tri dau tien co dist = -1 (vi tri 0,0)
// Vi tri chua di qua co dist = 0 (gia tri mac dinh khi khai bao map)
map<pair<int,int>, int> dist; // Khoang cach
bool visited[MAX][MAX];

// bfs
void bfs(){
    // Khai bao 2 binh tam thoi de giu lai chi so cua binh A, B truoc khi do nuoc
    binhNuoc binhTempA;
    binhNuoc binhTempB;

    // Ban dau trong hang doi co vi tri xuat phat ( thoi diem ban dau cua 2 binh co 0 lit)
    // Khoang cach ban dau tu no toi chinh no la bang 0
    // Danh dau visited = true -> da di qua diem dau tien
    Q.push(pair<int,int>(0,0));
    dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)] = 0;
    visited[binhA.luongnuoc][binhB.luongnuoc] = true;

    // Bat dau vong lap, duyet bfs
    while(!Q.empty()){

        binhA.luongnuoc = Q.front().first;
        binhB.luongnuoc = Q.front().second;
        Q.pop();

        // Luu lai luong nuoc hien tai truoc khi do nuoc
        binhTempA = binhA;
        binhTempB = binhB;

        // Kiem tra dieu kien de bai truoc khi bat dau xu li
        if(checkStop(binhA,binhB)){
            cout << dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)];
            return;
        }

        // Bat dau xu li (do nuoc)
        // For : ...
        // Th1 : Do tu be vao binh A
        pourWater(binhA);
        if(!visited[binhA.luongnuoc][binhB.luongnuoc]){
            Q.push(pair<int,int>(binhA.luongnuoc,binhB.luongnuoc));
            dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)] = dist[pair<int,int>(binhTempA.luongnuoc,binhTempB.luongnuoc)] + 1;
            visited[binhA.luongnuoc][binhB.luongnuoc] = true;
            //cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
        }
        binhA = binhTempA;
        binhB = binhTempB; // Tra lai trang thai ban dau cho binh A,B

        // Th2 : do tu binh B vao binh A
        pourWater(binhB,binhA);
        if(!visited[binhA.luongnuoc][binhB.luongnuoc]){
            Q.push(pair<int,int>(binhA.luongnuoc,binhB.luongnuoc));
            dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)] = dist[pair<int,int>(binhTempA.luongnuoc,binhTempB.luongnuoc)] + 1;
            visited[binhA.luongnuoc][binhB.luongnuoc] = true;
            //cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
        }
        binhA = binhTempA;
        binhB = binhTempB; // Tra lai trang thai ban dau cho binh A,B

        // Th3 : do tu be vao binh B
        pourWater(binhB);
        if(!visited[binhA.luongnuoc][binhB.luongnuoc]){
            Q.push(pair<int,int>(binhA.luongnuoc,binhB.luongnuoc));
            dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)] = dist[pair<int,int>(binhTempA.luongnuoc,binhTempB.luongnuoc)] + 1;
            visited[binhA.luongnuoc][binhB.luongnuoc] = true;
            //cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
        }
        binhA = binhTempA;
        binhB = binhTempB; // Tra lai trang thai ban dau cho binh A,B

        // Th4 : do tu binh A vao binh B
        pourWater(binhA,binhB);
        if(!visited[binhA.luongnuoc][binhB.luongnuoc]){
            Q.push(pair<int,int>(binhA.luongnuoc,binhB.luongnuoc));
            dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)] = dist[pair<int,int>(binhTempA.luongnuoc,binhTempB.luongnuoc)] + 1;
            visited[binhA.luongnuoc][binhB.luongnuoc] = true;
            //cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
        }
        binhA = binhTempA;
        binhB = binhTempB; // Tra lai trang thai ban dau cho binh A,B

        // Th5 : Do tu binh 1 vao be
        pourWater(binhA,true);
        if(!visited[binhA.luongnuoc][binhB.luongnuoc]){
            Q.push(pair<int,int>(binhA.luongnuoc,binhB.luongnuoc));
            dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)] = dist[pair<int,int>(binhTempA.luongnuoc,binhTempB.luongnuoc)] + 1;
            visited[binhA.luongnuoc][binhB.luongnuoc] = true;
            //cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
        }
        binhA = binhTempA;
        binhB = binhTempB; // Tra lai trang thai ban dau cho binh A,B

        pourWater(binhB,true);
        if(!visited[binhA.luongnuoc][binhB.luongnuoc]){
            Q.push(pair<int,int>(binhA.luongnuoc,binhB.luongnuoc));
            dist[pair<int,int>(binhA.luongnuoc,binhB.luongnuoc)] = dist[pair<int,int>(binhTempA.luongnuoc,binhTempB.luongnuoc)] + 1;
            visited[binhA.luongnuoc][binhB.luongnuoc] = true;
            //cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
        }
        // th cuoi khong can phai tra lai gia tri cho binh A,B do khong xet nua =))
    }

    cout << "-1";
}
int main(){

    inputData();
    bfs();

    return 0;
}
