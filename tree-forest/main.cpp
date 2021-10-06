#include<bits/stdc++.h>
#include "func.cpp"
#include<time.h>
using namespace std;
const int MAX = 1000000;

int parent[MAX]; // parent of node i__th
string name_node[MAX]; // name of node i_th
vector<int> children[MAX]; // list children of node i_th


void init(){
    ifstream f;
    f.open("input.txt", ios::in); // read file input
    for(int i=0; i<MAX; i++){ // assign init parent of node is -1 : no parent
        parent[i] = -1;
    }

    string strParam;
    int cnt = 0;

    cout << "LIST TREE : \n";
    while(getline(f, strParam)){
        vector<string> token = simple_tokenizer(strParam);
        int id_node = string_parse_int(token[0]);
        int id_parent = string_parse_int(token[1]);
        string name = token[2];

        parent[id_node] = id_parent; // assign parent node for each node
        name_node[id_node] = name;  // add new node to list of children parent node

        children[id_parent].push_back(id_node);

        cout << id_node << "\t" << id_parent << "\t" << name << "\n";
        cnt++;
    }; f.close();

    cout << "______\n\n";
}

// function check X is parent ( parent of parent,...) of Y?
bool check_X_Y(int X, int Y){
    int pa = parent[Y]; if(pa == X) return true;
    while(pa != X && pa != 0){
        pa = parent[pa];
        if(pa == X) return true;
    }

    return false;
}

// trace path from Y to X in tree
vector<int> trace(int X, int Y){
    vector<int> path;

    if(!check_X_Y(X, Y)) {
        cout << "X isn't parent of Y";
        return path; // with size = 0
    }

    path.push_back(Y);
    int pa = parent[Y]; path.push_back(pa);

    while(pa != X && pa != 0){
        pa = parent[pa];
        path.push_back(pa);
    }

    return path;
}

// print all of node children (children of children, ...) of node X
void print_children(int X){
    if(children[X].size() == 0){
        return;
    } else {
        for(int i : children[X]){
            cout << i << " " << name_node[i] << "\n";
            print_children(i);
        }
    }
}

/*-----------------------------*/
void bai_2(int X, int Y){
    cout << "Path form " << Y << " to " << X << " : ";
    clock_t start, stop;
    start = clock();

    vector<int> path = trace(X, Y);
    stop = clock();

    for(int i=0; i<path.size()-1; i++){
        cout << path[i] << "=>";
    }; cout << path[path.size()-1];

    cout << ", time of algorithms : " << stop - start << " ms\n\n-------------------\n";
}

void bai_3(int X){
    clock_t start, stop;

    cout << "List childrens of node " << X << " : \n";
    start = clock();
    print_children(X);
    stop = clock();

    cout << "\ntime of algorithms : " << stop - start << " ms\n\n----------------\n";
}
int main()
{
    init();
    bai_2(1,4);
    bai_3(1);

    return 0;
}
