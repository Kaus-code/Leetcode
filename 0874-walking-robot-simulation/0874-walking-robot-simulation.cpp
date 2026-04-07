class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // {N,E,S,W} 
        vector<vector<int>> direction ={{0,1},{1,0},{0,-1},{-1,0}};
        int dir=0;

        int x=0,y=0;
        int maxdist=0;

        set<pair<int,int>> obs;

        for(auto &o:obstacles)
        {
            obs.insert({o[0],o[1]});
        }

        for(int cmd:commands)
        {
            if(cmd==-2)
            {
                //turn left
                dir=(dir+3)%4;
            }
            else if(cmd==-1)
            {
                //turn right
                dir=(dir+1)%4;
            }
            else
            {
                //move fwd cmd steps
                for(int i=0;i<cmd;i++)
                {
                    int nx=x+ direction[dir][0];
                    int ny=y +direction[dir][1];

                    if(obs.count({nx,ny}))
                        break;

                   x=nx;
                   y=ny;
                   maxdist=max(maxdist,x*x+y*y);
                }
            }
        }

        return maxdist;
    }
};