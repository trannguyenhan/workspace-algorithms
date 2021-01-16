#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Graph
{
 private:
  vector< set<int> > adj;
  int n;
  int m;
 public:
  Graph(int n)
  {
    this->n = n;
    this->m=0;
    adj = vector< set<int> > (n);
  }

  Graph(istream &in)
  {
    in>>n;
    in>>m;
    adj = vector< set<int> > (n);

    int u, v;
    for (int i = 0; i < m; i++) {
      in>> u;
      in>> v;
      add_edge(u, v);
    }
  }
  set<int> const neighbors(int u)
  {
    return adj[u];
  }
  void add_edge(int u, int v)
  {
    adj[u].insert(v);
    adj[v].insert(u);
  }
  bool has_edge(int u, int v)
  {
    return (adj[u].count(v) > 0);
  }
  int V()
  {
    return n;
  }
  int E()
  {
    return m;
  }
  vector<int>  deg_sequence()
  {
    vector<int> seq (V());
    for (size_t i = 0; i < V(); i++)
    {
      seq[i] = adj[i].size();
    }
    sort (seq.begin(), seq.end());

    return seq;
  }
};




bool check (vector<int> &p, Graph &G, Graph &H)
{
  if (G.V() != H.V()) return false;
  if (G.E() != H.E()) return false;

    if (G.deg_sequence() != H.deg_sequence()) return false;

    for (int u = 0; u < G.V(); ++u)
    {
        if (G.neighbors(u).size() != H.neighbors(p[u]).size()) return false;
        for(int v: G.neighbors(u))
        {
            if (!H.has_edge(p[u], p[v])) return false;
        }
    }

  return true;
}

/***
 * TODO: Nên tìm song ánh từ các đỉnh cùng bậc tới đỉnh cùng bậc 
 * 
 * */

bool check_isomorphism_graph (Graph &G, Graph &H)
{
  int n = G.V();
  vector<int> p(n);
  for (int i = 0; i < n; ++i)  p[i] = i;

  do
  {
      if (check (p, G, H ))
      {
          for(int i: p)
            cout<<i<<" ";
          cout<<endl;
          return true;
      }
  } while (next_permutation(p.begin(), p.end()));

  return false;
}

int main(int argc, char *argv[]) {
  if (argc < 2)
  {
    cout<<"Usage: graph1.txt graph2.txt"<<endl;
    return 0;
  }

  ifstream in1 (argv[1]);
  ifstream in2 (argv[2]);
  if (!in1 || !in2){
    cout<<"Cannot open files!"<<endl;
    return 0;
  }
  Graph G(in1);
  Graph H(in2);

  if (check_isomorphism_graph(G, H)) cout<<"Yes"<<endl;
  else cout<<"No";
  return 0;
}