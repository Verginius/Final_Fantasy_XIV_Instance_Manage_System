#ifndef LARGEINSTANCEEX_H
#define LARGEINSTANCEEX_H

#include <string>
#include "Instance.h"

class LargeInstanceEx : public Instance{
public:
    virtual ~LargeInstanceEx(){}
    LargeInstanceEx(long id,std::string name,int pl,int el,int pn,int tl,int ATP);
    LargeInstanceEx(std::string name,int pl,int el,int pn,int tl,int ATP);
    void SetATPNum(int ATP){this->ATP=ATP;}
    int getATPNum()const{return ATP;}
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
private:
    int ATP;
};

#endif // LARGEINSTANCEEX_H
