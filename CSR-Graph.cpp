#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class CSR{
    public:
        vector<int> edge;
        vector<int> vertex;
        int nodes;
        int count=0;
    void constructCSR(){
        for(int i=0;i<nodes;i++){
            int temp;
            vertex.push_back(count);
            cin>>temp;
            while(temp<nodes && temp>=0){
                edge.push_back(temp);
                cin>>temp;
                count++;
            }
        }
        vertex.push_back(edge.size());
    }
    void display(){
            for(int i=0;i<nodes;i++){
                cout<<i<<"->";
                for(int j=vertex[i];j<vertex[i+1];j++){
                    cout<<edge[j]<<" ";
                }
                cout<<endl;
            }
            /*cout<<vertex.size()-1<<"->";
            for (int j=vertex[vertex.size()-1];j<edge.size();j++){
                cout<<edge[j]<<" ";
            }*/
    }
    vector<int> bfspath(int s,int e){
        queue<int>q;
        vector<bool>visited(nodes,false);
        vector<int>prev(nodes,-1);
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=vertex[x];i<vertex[x+1];i++){
                if(!visited[edge[i]]){
                    visited[edge[i]]=true;
                    prev[edge[i]] = x;
                    q.push(edge[i]);
                }
            }
            }    
         vector<int>path;   
         for(int i=e;i!=-1;i=prev[i]){
             path.push_back(i);
         }
         reverse(path.begin(),path.end());
          return path;
         
    }
    void bfs_algo(vector<bool>&v,int i){
        queue<int>q;
        q.push(i);
        v[i]=true;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = vertex[x]; i < vertex[x + 1]; i++)
            {
                if (!v[edge[i]])
                {
                    v[edge[i]] = true;
                    q.push(edge[i]);
                }
            }
        }
    }
    int graphcomponent(){
            vector<bool>check(nodes,0);
            int components=0;
            for(int i=0;i<nodes;i++){
                if(check[i]==false){
                      bfs_algo(check,i);  
                      components++;
                }
            }
            return components;
    }

};
int main(){
    CSR g1;
    int nc;
    cin>>nc;
    g1.nodes=nc;
    g1.constructCSR();
    g1.display();
    cout<<endl;

    /*vector<int>result=g1.bfspath(s,e);
    for(auto i:result){
        cout<<i<<" ";
    }*/
    int grapgcomponent = g1.graphcomponent();
    cout<<grapgcomponent<<endl;
}

/*
4=no of nodes     0
1             edge 1
2              edge 1 2
3  1 2 3 count=3
-1   
0
2
-1
0
1
-1
0
-1
*/
