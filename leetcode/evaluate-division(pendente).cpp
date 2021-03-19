class Solution {
public:
    double getValue(string x,string y,unordered_map< string,unordered_map <string,double> > &adjList, unordered_set<string>&isvisited){
    double val;
    isvisited.insert(x);
    if(adjList[x].find(y)!=adjList[x].end()){
        return adjList[x][y];
    }
    else{
        for(auto str: adjList[x]){
            if(isvisited.find(str.first)==isvisited.end()){
                adjList[str.first][y]=getValue(str.first, y, adjList, isvisited);  
                if(val>=0) {
                    return adjList[x][str.first]*adjList[str.first][y]; 
                }
            }
        }
    }
    return -1;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    unordered_map< string, unordered_map<string, double> > adjList;
    for(int i = 0; i< equations.size(); i++){
        adjList[equations[i].first][equations[i].second]=values[i];
        if(values[i]!=0) {
            adjList[equations[i].second][equations[i].first] = 1.0/(double)values[i];
            adjList[equations[i].first][equations[i].first]=1;
            adjList[equations[i].second][equations[i].second]=1;
        }
        else{
            adjList[equations[i].second][equations[i].first]=-1;
            adjList[equations[i].first][equations[i].first]=-1;
        } 
    }
    vector<double> ans(queries.size());
    unordered_set <string> isvisited;
    for(int i = 0; i< queries.size(); i++){
        if(adjList.find(queries[i].first)==adjList.end()){
            ans[i]=-1;
        }
        else{
            ans[i]=getValue(queries[i].first, queries[i].second, adjList, isvisited);
        }   
    }
    return ans;
}
};