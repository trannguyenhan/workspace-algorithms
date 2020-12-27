#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<string> document_train;
vector<string> document_test;
set<string> dictionary;
map<string, int> df; // so van ban chua tu t
map<string, vector<int> > f; // tu i xuat hien trong van ban d bao nhieu lan
vector<int> f_max; // tan suat xuat hien tu xuat hien nhieu nhat trong van ban i

// input
void input(){
    cin >> n;
    string str_tmp;
    getline(cin, str_tmp);

    for(int i=0; i<n; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_train.push_back(str_tmp);
    }

    cin >> q;
    getline(cin, str_tmp);
    for(int i=0; i<q; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_test.push_back(str_tmp);
    }
}

// split string
vector<string> split_string(string str){
    vector<string> vt;

    while (!str.empty()){
        string tmp = str.substr(0, str.find(","));
        int pos = tmp.find(" ");

        if(pos > tmp.size())
            vt.push_back(tmp);
        else {
            while(pos <= tmp.size()){
                tmp.erase(pos,1);
                pos = tmp.find(" ");
            }
            vt.push_back(tmp);
        }
        if (str.find(",") > str.size()){
            break;
        } else {
            str.erase(0, str.find(",") + 1);
        }
    }

    return vt;
}

// preprocessing
void pre_processing(){
    // create dictionary
    for(string str_target : document_train){
        vector<string> str_tmp = split_string(str_target);
        for(string str : str_tmp){
            dictionary.insert(str);
        }
    }

    // tinh xem tu word nam trong bao nhieu van ban
    // tinh xem word xuat hien bao nhieu lan trong van ban i
    for(string word : dictionary){
        int index1 = 0;
        int index2 = 0;
        vector<int> list_f;
        for(string str_target : document_train){
            vector<string> str_tmp = split_string(str_target);

            index1 = 0;
            for(string word_tmp : str_tmp){
                if(word == word_tmp) index1++;
            }
            list_f.push_back(index1);

            auto ite = find(str_tmp.begin(), str_tmp.end(), word);
            if(ite != str_tmp.end()){
                index2++;
            }
        }
        f.insert({word, list_f});
        df.insert({word, index2});
    }

    // tinh xem word xuat hien bao nhieu lan trong van ban i
    /*
    for(string word : dictionary){
        vector<int> list_f;
        for(string str_target : document_train){
            vector<string> str_tmp = split_string(str_target);

            int index = 0;
            for(string word_tmp : str_tmp){
                if(word == word_tmp) index++;
            }

            list_f.push_back(index);
        }
        f.insert({word, list_f});
    }
    */
    // tinh tan suat tu xuat hien nhieu nhat trong van ban i
    for(string str_target : document_train){
        map<string, int> m;
        vector<string> str_tmp = split_string(str_target);

        // thiet lap tu dien mini m voi chi so : [sotu] [tansuatxuathien]
        int max_f = 0;
        for(string word_tmp : str_tmp){
            map<string, int>::iterator ite = m.find(word_tmp);
            if(ite == m.end()){ // neu tu nay chua co trong tu dien mini
                m.insert({word_tmp, 1});
            } else {
                ite->second += 1;
            }

            max_f = max(m[word_tmp], max_f);
        }
        f_max.push_back(max_f);
        /*
        int max_f = 0;
        for(auto v : m){
            max_f = max(max_f, v.second);
        }
        f_max.push_back(max_f);
        */
    }
}

int search_engine(string document){
    vector<string> list_word = split_string(document);

    double score_max = 0;
    int predict_label = -1;
    for(int i=0; i<n; i++){
        string train_doc = document_train[i];
        vector<string> list_word_train_doc = split_string(train_doc);

        double score = 0;
        for(string word : list_word){
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word) == list_word_train_doc.end()){ // tu nay khong xuat hien trong van ban
                continue;
            } else {
                int ftd = f[word].at(i);
                int maxfd = f_max[i];
                int dft = df[word];

                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n / dft);

                score += tf_word * idf_word;
            }
        }

        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }

    return predict_label + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    pre_processing();

    for(int i=0; i<q; i++)
        cout << search_engine(document_test[i]) << endl;

    /*
    for(int i=0; i<n; i++)
        cout << f_max[i] << " ";
    */
    /*
    for(string word : dictionary){
        cout << word << " ";
        cout << df[word] << endl;
    }

    cout << endl;

    for(string word : dictionary){
        cout << word << " ";
        for(int v : f[word]){
            cout << v << " ";
        }
        cout << endl;
    }*/
    return 0;
}

