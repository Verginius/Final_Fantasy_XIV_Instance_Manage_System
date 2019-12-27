#include <iostream>
#include <sstream>
#include "LargeInstance.h"

using namespace std;

LargeInstance::LargeInstance(long i,std::string n,int pl,int el,int pn,int tl,int ATG,int ATP)
    :Instance(i,n,pl,el,pn,tl),ATG(ATG),ATP(ATP){}
LargeInstance::LargeInstance(std::string n,int pl,int el,int pn,int tl,int ATG,int ATP)
    :Instance(n,pl,el,pn,tl),ATG(ATG),ATP(ATP){}

void LargeInstance::output()const{
    Instance::output();
    cout<<"  获得ATG数量:"<<getATGNum()<<endl
        <<"  获得ATP数量:"<<getATPNum()<<endl
        <<endl;
}
int LargeInstance::getType()const{
    return 0; //0 表示大型任务
}

std::string LargeInstance::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Instance::getInfo(); //输出基类的信息
    ostr<<ATG<<" "<<ATP<<endl; //输出子类信息
    return ostr.str();
}
