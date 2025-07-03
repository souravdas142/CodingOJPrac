// User function Template for C++
class disjoint{
    private:
    vector<int> parent,size;
    public:
    disjoint(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
    }
    
    int fup(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=fup(parent[node]);
    }
    void unionbysize(int u,int v){
        int ul=fup(u);
        int vl=fup(v);
        if(ul==vl) return;
        if(size[ul]>size[vl]){
            parent[vl]=ul;
            size[u]+=size[v];
        }else{
            parent[ul]=vl;
            size[v]+=size[u];
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int v, vector<vector<int>> &edges) {
        // code here
        disjoint ds(v);
        vector<pair<int,pair<int,int>>> chedge;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            chedge.push_back({wt,{u,v}});
        }
        sort(chedge.begin(),chedge.end());
        int mst=0;
        for(it: chedge){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.fup(u)!=ds.fup(v)){
                mst+=wt;
                ds.unionbysize(u,v);
            }
        }
        return mst;
    }
};