#ifndef BOSSINSTANCE_H
#define BOSSINSTANCE_H

#include <string>
#include "Instance.h"

class BossInstance : public Instance{
public:
    virtual ~BossInstance(){}
    BossInstance(long id,std::string name,int pl,int el,int pn,int tl,int exp,int gold);
    BossInstance(std::string name,int pl,int el,int pn,int tl,int exp,int gold);
    void setExp(int exp){this->exp=exp;}
    void SetGold(int gold){this->gold=gold;}
    int getExp()const{return exp;}
    int getGold()const{return gold;}
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
private:
    int exp;
    int gold;
};

#endif // BOSSINSTANCE_H
