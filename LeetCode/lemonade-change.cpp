class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0,c10=0;
        for(auto b:bills){
            if(b==5)++c5;
            else if(b==10)--c5,++c10;
            else if(c10)--c10,--c5;
            else c5-=3;
            if(c5<0||c10<0)return false;
        }
        return true;
    }
};
