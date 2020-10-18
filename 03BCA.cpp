#include<bits/stdc++.h>
using namespace std;
const int MAX = 40;

int n, m;
int course[MAX]; // course a assign for teacher course[a]
int theTeacherChoose[MAX]; // Which teacher choose this course?
vector<vector<int> > listOfCourse; // list of course teacher can teach
vector<vector<int> > listOfPairsOfConflicting; // list of pairs(course) of conflicting
int theLoadOfTeacher[MAX];
int theLoadMaxOfTeacher = 0;
int minAll = 2147483647;

/*enter data from standand input*/
void inputData(){
    int k;
    cin >> m >> n;
    listOfCourse.resize(m);
    for(int i=0; i<m; i++){
        cin >> k;
        for(int j=0; j<k; j++){
            int temp;
            cin >> temp;
            listOfCourse[i].push_back(temp);
        }
    }

    cin >> k;
    listOfPairsOfConflicting.resize(n+1);
    for(int i=0; i<k; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        listOfPairsOfConflicting[temp1].push_back(temp2); // course temp1 config with temp2
        listOfPairsOfConflicting[temp2].push_back(temp1); // if course temp1 config temp2, so course temp2 config with temp1 too
    }

}

/*recursive backtracking*/
//check procedure
bool check(int a, int i){ // Khoa hoc a duoc gan cho thay giao i
    int tick = 0;
    for(int j=0; j<listOfCourse[i].size(); j++)
        if(listOfCourse[i].at(j) == a)
            tick++;
    if(tick == 0) return false;

    for(int j=0; j<listOfPairsOfConflicting[a].size(); j++){
        if(course[listOfPairsOfConflicting[a].at(j)] == i && listOfPairsOfConflicting[a].at(j) < a)
            return false;
    }
    return true;
}

void solution(){
    minAll = min(minAll,theLoadMaxOfTeacher);
}

void TRY(int a){
    for(int i=0; i<m; i++){
        if(check(a,i)){
            course[a] = i;
            theLoadOfTeacher[i]++;
            int pre = theLoadMaxOfTeacher;
            theLoadMaxOfTeacher = max(theLoadMaxOfTeacher,theLoadOfTeacher[i]);

            if(a==n) solution();
            else
                if(theLoadMaxOfTeacher < minAll ) TRY(a+1);

            theLoadOfTeacher[i]--;
            theLoadMaxOfTeacher = pre;
        }
    }
}

int main(){
    inputData();
    TRY(1);
    cout << minAll;

    return 0;
}
