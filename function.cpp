#include <iostream>
#include "function.h"
#include "LargeInstance.h"
#include "LargeInstanceEx.h"
#include "BossInstance.h"

using namespace std;

char menu(){
    cout<<" 0) 退出系统\n";
    cout<<" 1) 添加副本\n";
    cout<<" 2) 移除副本\n";
    cout<<" 3) 查看指定副本\n";
    cout<<" 4) 查看所有副本\n";
    cout<<"请输入功能选项:";
    char choice;
    cin>>choice;
    return choice;
}
void doAddInstance(InstanceManage& ins){
    string name;
    int playerLevel,equipmentLevel,playerNum,timeLimit;
    int ATG,ATP,exp,gold;
    int type;
    cout<<"选择副本类型(0-大型任务，1-高难大型任务，2-歼灭战)";
    cin>>type;
    fflush(stdin);
    cout<<"输入副本名称:";
    getline(cin,name);
    cout<<"输入人物等级、装备等级、玩家人数和时间限制:";
    cin>>playerLevel>>equipmentLevel>>playerNum>>timeLimit;
    if(type==0){
        cout<<"输入获得ATG和ATP数量:";
        cin>>ATG>>ATP;
        ins.addInstance(new
        LargeInstance(name,playerLevel,equipmentLevel,playerNum,timeLimit,ATG,ATP));
    }
    else if(type==1){
        cout<<"输入获得ATP数量:";
        cin>>ATP;
        ins.addInstance(new
        LargeInstanceEx(name,playerLevel,equipmentLevel,playerNum,timeLimit,ATP));
    }
    else if(type==2){
        cout<<"输入获得经验和金币数量:";
        cin>>exp>>gold;
        ins.addInstance(new
        BossInstance(name,playerLevel,equipmentLevel,playerNum,timeLimit,exp,gold));
    }
}
void doRemoveInstance(InstanceManage& ins){
    long id;
    cout<<"Input id:";
    cin>>id;
    ins.removeInstance(id);
}
void doViewInstance(const InstanceManage& ins){
    long id;
    cout<<"Input id:";
    cin>>id;
    ins.viewInstance(id);
}
void doViewAllInstance(const InstanceManage& ins){
    ins.viewAllInstance();
}
