#include<iostream>
#include<vector>
using namespace std;
struct Edge{
    int start,end,weight;
};
class Graph{
    public:
    int v,e;
    vector<Edge>E;
    void addEdge(int u,int v,int w){
        Edge temp;
         temp.start = u,temp.end = v,temp.weight = w;
         E.push_back(temp);
    }
    void sortEdges(){

        for (int k = 0; k < e - 1; k++){
            for (int i = 0; i < e - k - 1; i++){
                if (E[i].weight>E[i+1].weight){
                    swap(E[i],E[i+1]);
                }
            }
        }//sorting is O(n*n) can be minimised using O(nlog(n)) technique
    }
};
class subset{
public:
    int parent, rank;
};
int find(vector<subset>ss, int i){
    if (ss[i].parent != i)
        ss[i].parent = find(ss, ss[i].parent);

    return ss[i].parent;
}
void Union(vector<subset>& ss, int x, int y)
{
    int xroot = find(ss, x);
    int yroot = find(ss, y);
    if (ss[xroot].rank < ss[yroot].rank)
        ss[xroot].parent = yroot;
    else if (ss[xroot].rank > ss[yroot].rank)
        ss[yroot].parent = xroot;
    else
    {
        ss[yroot].parent = xroot;
        ss[xroot].rank++;
    }
}
int Kruskal(Graph g)
{
    int V = g.v;
    vector<Edge> result(V);
    int e = 0, i = 0;
    vector<subset> ss(V);
    for (int i = 0; i < V; i++)
    {
        ss[i].parent = i;
        ss[i].rank = 0;
    }
    while (e < V - 1 && i < g.e)
    {
        Edge next_edge = g.E[i++];
        int x = find(ss, next_edge.start);
        int y = find(ss, next_edge.end);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(ss, x, y);
        }
    }
    int msp = 0;
    for (int i = 0; i < e; i++)
    {
        cout << result[i].start << " -- " << result[i].end << " == " << result[i].weight << endl;
        msp += result[i].weight;
    }
    cout << endl;
    return msp;
}

int main(){
    int v,e;
    cin>>v>>e;
    Graph g1;
    g1.v =v,g1.e = e;
    g1.addEdge(0,1,10);
    g1.addEdge(0,2,6);
    g1.addEdge(0,3,5);
    g1.addEdge(1,3,15);
    g1.addEdge(2,3,4);
    g1.sortEdges();
    int res = Kruskal(g1);
    cout<<res<<endl;
}

