#include <iostream>
#include <sstream>
#include "Instance.h"

using namespace std;

long Instance::nextId=100;
Instance::Instance(std::string n,int pl,int el,int pn,int tl)
    :Instance(autoNextId(),n,pl,el,pn,tl){}
Instance::Instance(long i,std::string n,int pl,int el,int pn,int tl)
    :id(i),name(n),playerLevel(pl),equipmentLevel(el),playerNum(pn),timeLimit(tl){}
void Instance::output()const{
    cout<<endl;
    cout<<"副本编号(id):"<<id<<endl;
    cout<<"  副本名称:"<<name<<endl;
    cout<<"  人物等级:"<<playerLevel<<endl;
    cout<<"  装备等级:"<<equipmentLevel<<endl;
    cout<<"  玩家人数:"<<playerNum<<endl;
    cout<<"  时间限制:"<<timeLimit<<endl;
}
string Instance::getInfo()const{
    ostringstream ostr;
    ostr<<getId()<<endl;
    ostr<<getName()<<endl;
    ostr<<getPlayerLevel()<<endl;
    ostr<<getEquipmentLevel()<<endl;
    ostr<<getPlayerNum()<<endl;
    ostr<<getTimeLimit()<<endl;
    return ostr.str();
}
