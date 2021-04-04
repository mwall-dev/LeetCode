 


class Solution {
public:
    vector<int> indices; //Stores indices of same group. i.e islands.
    vector<bool> visited; // Important so we only look at an island once.
    vector<vector<int>> adjList; // Not an adj_matrix but just each ele has a vector of nodes it has edges too.
    string indiceString; //Stores  string formed by indices in the same group.
    
    //DFS to get all indices in same group.
    void dfs(string &s,int n) {
    
        visited[n]=true;
        indices.push_back(n);
        indiceString+=s[n];
        for(int &i:adjList[n])
            if(!visited[i])
               dfs(s,i);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    
        adjList.resize(s.length());
        visited.resize(s.length(),false);
        
         //Create adjacency list using the indice pairs
        for(vector<int> &v:pairs) {            
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }
        
        
        for(int i=0;i<s.length();i++)
            if(!visited[i]) {
                indiceString="";  //Clear string formed by one group of indices before finding next group.
                indices.clear();  //Clear indices vector before finding another group.
                
                dfs(s,i); // Find all characters on this island.
                sort(indiceString.begin(),indiceString.end());     //Sort the characters in the same group.
                sort(indices.begin(),indices.end()); //Sort the indices in the same group.            
                
                //Replace all the indices in the same group with the sorted characters.
                for(int i=0;i<indices.size();i++) s[indices[i]]=indiceString[i]; 
                    
            }
        
        return s;
    }
};
