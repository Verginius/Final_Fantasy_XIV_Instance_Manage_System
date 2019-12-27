#include <iostream>
#include <sstream>
#include "BossInstance.h"

using namespace std;

BossInstance::BossInstance(long i,std::string n,int pl,int el,int pn,int tl,int exp,int gold)
    :Instance(i,n,pl,el,pn,tl),exp(exp),gold(gold){}
BossInstance::BossInstance(std::string n,int pl,int el,int pn,int tl,int exp,int gold)
    :Instance(n,pl,el,pn,tl),exp(exp),gold(gold){}

void BossInstance::output()const{
    Instance::output();
    cout<<"  获得经验数量:"<<getExp()<<endl
        <<"  获得金币数量:"<<getGold()<<endl
        <<endl;
}
int BossInstance::getType()const{
    return 2; //2 表示歼灭战
}

std::string BossInstance::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Instance::getInfo(); //输出基类的信息
    ostr<<exp<<" "<<gold<<endl; //输出子类信息
    return ostr.str();
}
