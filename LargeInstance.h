#ifndef LARGEINSTANCE_H
#define LARGEINSTANCE_H

#include <string>
#include "Instance.h"

class LargeInstance : public Instance{
public:
    virtual ~LargeInstance(){}
    LargeInstance(long id,std::string name,int pl,int el,int pn,int tl,int ATG,int ATP);
    LargeInstance(std::string name,int pl,int el,int pn,int tl,int ATG,int ATP);
    void setATGNum(int ATG){this->ATG=ATG;}
    void SetATPNum(int ATP){this->ATP=ATP;}
    int getATGNum()const{return ATG;}
    int getATPNum()const{return ATP;}
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
private:
    int ATG;
    int ATP;
};

#endif // LARGEINSTANCE_H
