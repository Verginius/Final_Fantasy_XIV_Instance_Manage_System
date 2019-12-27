#include <iostream>
#include "Instance.h"
#include "InstanceManage.h"
#include "function.h"

using namespace std;

int main()
{
    cout << "===============================================================================" << endl;
    cout << "=          /\\                 欢迎使用最终幻想14副本信息管理系统              =" << endl;
    cout << "=         /  \\                 当前游戏版本：v5.05（2019/12/24）              =" << endl;
    cout << "=        /    \\                                                               =" << endl;
    cout << "=       /      \\                                                              =" << endl;
    cout << "=       \\      /                                                              =" << endl;
    cout << "=        \\    /                      “倾听 感受 思考”                       =" << endl;
    cout << "=         \\  /                                                                =" << endl;
    cout << "=          \\/                                                                 =" << endl;
    cout << "===============================================================================" << endl;
    char choice;
    InstanceManage ins;
    ins.readData("D\\FFXIV.data");
    while(true){
        choice = menu();
        if(choice=='0')
            break;
        switch(choice){
        case '1':
            doAddInstance(ins);
            break;
        case '2':
            doRemoveInstance(ins);
            break;
        case '3':
            doViewInstance(ins);
            break;
        case '4':
            doViewAllInstance(ins);
            break;
        default:
            cout<<"无效输入! 请重试!\n";
            break;
        }
    }
    cout<<"真有你们的啊！Square Enix!\n";
    ins.saveData("D\\FFXIV.data");
    return 0;
}
