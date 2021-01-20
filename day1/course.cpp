/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?*/
class Solution {
public:
    bool iscyclic(int i,bool *vis,bool *rec,vector<int> g[]){
        if(vis[i]==false){
            vis[i]=true;
            rec[i]=true;
            for(auto x:g[i]){
                if(!vis[x] and iscyclic(x,vis,rec,g)){
                    return true;
                }
                else if(rec[x]){
                    return true;
                }
            }
        }
        rec[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> g[numCourses];
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        bool vis[numCourses+1];
        bool rec[numCourses+1];
        
        memset(vis,false,sizeof(vis));
        memset(rec,false,sizeof(rec));
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                //cout<<i<<endl;
                if(iscyclic(i,vis,rec,g)){
                    cout<<i<<endl;
                    return false;
                }
                
            }
        }
        return true;
        
    }
};
