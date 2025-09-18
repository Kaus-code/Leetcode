class TaskManager {
public:
    typedef tuple <int,int,int> t;
    priority_queue<t> pq;
    unordered_map<int,pair<int,int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t:tasks){
            int a=t[0];
            int b = t[1];
            int c = t[2];
            pq.push({c,b,a});
            mp[b] = {c,a};
        }
    }
    void add(int u, int to, int p) {
        pq.push({p,to,u});
        mp[to] = {p,u};
    }
    
    void edit(int to, int ne) {
        int u = mp[to].second;
        mp[to] = {ne,u};
        pq.push({ne,to,u});
    }
    
    void rmv(int to) {
        mp.erase(to);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [a,b,c] = pq.top();
            if(!mp.count(b)){
                pq.pop();
                continue;
            }
            auto [prio,user] = mp[b];
            if(prio!=a || user!=c){
                pq.pop();
                continue;
            }
            pq.pop();
            mp.erase(b);
            return c;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */