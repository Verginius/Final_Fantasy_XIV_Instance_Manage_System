#include <iostream>
#include <sstream>
#include "LargeInstanceEx.h"

using namespace std;

LargeInstanceEx::LargeInstanceEx(long i,std::string n,int pl,int el,int pn,int tl,int ATP)
    :Instance(i,n,pl,el,pn,tl),ATP(ATP){}
LargeInstanceEx::LargeInstanceEx(std::string n,int pl,int el,int pn,int tl,int ATP)
    :Instance(n,pl,el,pn,tl),ATP(ATP){}

void LargeInstanceEx::output()const{
    Instance::output();
    cout<<"  获得ATP数量:"<<getATPNum()<<endl;
}
int LargeInstanceEx::getType()const{
    return 1; //1 表示高难大型任务
}

std::string LargeInstanceEx::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Instance::getInfo(); //输出基类的信息
    ostr<<ATP<<endl; //输出子类信息
    return ostr.str();
}
