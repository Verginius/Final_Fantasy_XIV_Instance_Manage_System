#ifndef FUNCTION_H
#define FUNCTION_H

#include "InstanceManage.h"

char menu();
void doAddInstance(InstanceManage& ins);
void doRemoveInstance(InstanceManage& ins);
void doViewInstance(const InstanceManage& ins);
void doViewAllInstance(const InstanceManage& ins);
void doEditInstance(const InstanceManage& ins);

#endif // FUNCTION_H
