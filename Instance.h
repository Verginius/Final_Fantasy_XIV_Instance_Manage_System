#ifndef INSTANCE_H
#define INSTANCE_H

#include <iostream>

class Instance{
public:
    virtual ~Instance(){}
    Instance()=default;
    Instance(long i,std::string n,int pl,int el,int pn,int tl);
    Instance(std::string n,int pl,int el,int pn,int tl);
    void setPlayerLevel(int playerLevel){this->playerLevel=playerLevel;}
    void setEquipmentLevel(int equipmentLevel){this->equipmentLevel=equipmentLevel;}
    void setName(std::string name){this->name=name;}
    void setPlayerNum(int playerNum){this->playerNum=playerNum;}
    void setTimeLimit(int timeLimit){this->timeLimit=timeLimit;}
    std::string getName()const{return name;}
    int getPlayerLevel()const{return playerLevel;}
    int getEquipmentLevel()const{return equipmentLevel;}
    int getPlayerNum()const{return playerNum;}
    int getTimeLimit()const{return timeLimit;}
    double getId()const{return id;}
    virtual void output()const;
    virtual int getType()const=0; //纯虚函数
    virtual std::string getInfo()const;
    static void setNextId(long id){nextId=id;}
    static long getNextId(){return nextId;}
private:
    long id;
    std::string name;
    int playerLevel;
    int equipmentLevel;
    int playerNum;
    int timeLimit;
    static long nextId;
    long autoNextId(){return nextId++;}
};

#endif // INSTANCE_H
