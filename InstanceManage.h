#ifndef INSTANCEMANAGE_H
#define INSTANCEMANAGE_H

#include <vector>
#include <algorithm>
#include "Instance.h"

class InstanceManage{
public:
    InstanceManage()=default;
    ~InstanceManage();
    InstanceManage(const InstanceManage& i)=delete;
    InstanceManage& operator=(const InstanceManage& i)=delete;
    void addInstance(Instance* p);
    void removeInstance(int id);
    void viewInstance(int id)const;
    void viewAllInstance()const;
    void readData(std::string filename);
    void saveData(std::string filename);
private:
    std::vector<Instance*>pInstances;
    Instance* findInstanceById(int id);
    const Instance* findInstanceById(int id)const;
    std::vector<Instance*>::iterator getIterator(Instance* p);
    int sortType=0; //记录当前排序类型
    void sortInstances();
    void sortInstancesByType(int type);
};

#endif // INSTANCEMANAGE_H
