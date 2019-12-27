#include "Instance.h"
#include "InstanceManage.h"
#include "LargeInstance.h"
#include "LargeInstanceEx.h"
#include "BossInstance.h"
#include <iostream>
#include <fstream>

using namespace std;

InstanceManage::~InstanceManage(){
    for(auto e:pInstances)
        delete e;
}
void InstanceManage::addInstance(Instance* p){
    Instance* pInstance=findInstanceById(p->getId());
    if(pInstance!=nullptr){
        cout<<"编号为"<<p->getId()<<"的副本已经存在!\n";
        return;
    }
    pInstances.push_back(p);
    sortInstances(); //添加副本后根据当前规则重新排序
}
void InstanceManage::removeInstance(int id){
    Instance* pCommodity=findInstanceById(id);
    if(pCommodity==nullptr){
        cout<<"编号为"<<id<<"的副本不存在!\n";
        return;
    }
    delete pCommodity;
    pInstances.erase(getIterator(pCommodity));
}
void InstanceManage::viewInstance(int id)const{
    const Instance* pCommodity=findInstanceById(id);
    if(pCommodity==nullptr){
        cout<<"编号为"<<id<<"的副本不存在!\n";
        return;
    }
    pCommodity->output();
}
void InstanceManage::viewAllInstance()const{
    cout<<"副本种类:"<< pInstances.size()<<endl;
    if(pInstances.size()==0)
        return;
    cout<<"指定排序方式(0-副本id,1-副本名称):";
    int type;
    cin>>type;
    const_cast<InstanceManage*>(this)->sortInstancesByType(type);
    for(auto e:pInstances)
        e->output();
}
void InstanceManage::saveData(string filename){
    ofstream out(filename);
    if(out){
        out<<pInstances.size()<<endl;
        out<<Instance::getNextId()<<endl;
        for(auto e : pInstances){
            out<<e->getInfo();
        }
    }
}

Instance* InstanceManage::findInstanceById(int id){
    vector<Instance*>::iterator it=find_if(pInstances.begin(),
    pInstances.end(), [=](Instance* p){return p->getId()==id;});
    if(it!=pInstances.end())
        return *it;
    return nullptr;
}
const Instance* InstanceManage::findInstanceById(int id)const{
    vector<Instance*>::const_iterator it=find_if(pInstances.begin(),
    pInstances.end(), [=](const Instance* p){return p->getId()==id;});
    if(it!=pInstances.end())
        return *it;
    return nullptr;
}
vector<Instance*>::iterator InstanceManage::getIterator(Instance* p){
    for(auto it=pInstances.begin();it!=pInstances.end();++it)
        if(*it==p)
            return it;
    return pInstances.end();
}
void InstanceManage::sortInstances(){
    switch(sortType){
    case 0: //根据 id 排序
        sort(pInstances.begin(),pInstances.end(),
        [=](Instance* p1,Instance* p2){
        return p1->getId()<p2->getId();});
        break;
    case 1: //根据名称排序
        sort(pInstances.begin(),pInstances.end(),
        [=](Instance* p1,Instance* p2){
        return p1->getName()<p2->getName();});
        break;
    }
}
void InstanceManage::sortInstancesByType(int type){
    if(type==sortType) //已经按指定规则排序，直接返回
        return;
    sortType=type;
    sortInstances();
}

void InstanceManage::readData(string filename){
    ifstream in(filename);
    if(in){
        int fileMax,fileSize;
        long nextId;
        in>>fileMax>>fileSize>>nextId;
        Instance::setNextId(nextId);
        int type;
        long id;
        string name,buf;
        int playerLevel,equipmentLevel,playerNum,timeLimit;
        int ATG,ATP,exp,gold;
        for(int i=0;i<fileSize;++i){
            in>>type;
            in>>id;
            getline(in,buf);
            getline(in,name);
            in>>playerLevel>>equipmentLevel>>playerNum>>timeLimit;
            if(type==0){
                in>>ATG;
                in>>ATP;
                addInstance(new
                LargeInstance(id,name,playerLevel,equipmentLevel,playerNum,timeLimit,ATG,ATP));
            }
            else if(type==1){
                in>>ATP;
                addInstance(new
                LargeInstanceEx(id,name,playerLevel,equipmentLevel,playerNum,timeLimit,ATP));
            }
            else if(type==2){
                in>>exp>>gold;
                addInstance(new
                BossInstance(id,name,playerLevel,equipmentLevel,playerNum,timeLimit,exp,gold));
            }
        }
    }
    sortInstances();
}
