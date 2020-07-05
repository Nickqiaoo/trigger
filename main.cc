#include<iostream>
#include"invite_module.h"

using namespace std;

int main(){
    InviteModule invite;
    int64_t roleid = 17201389569;

    string code = invite.convertRoleIdToCode(roleid);
    cout<<"code:"<<code<<endl;
    cout<<"id:"<<invite.convertCodeToRoleId(code)<<endl;
    return 0;
}