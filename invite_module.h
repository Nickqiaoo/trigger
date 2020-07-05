#pragma once

#include<unordered_map>

class InviteModule{
    public:
    InviteModule();
    ~InviteModule();

    public:
    

    //private:
    std::string convertRoleIdToCode(int64_t roleId);
    int64_t convertCodeToRoleId(std::string inviteCode);

    private:
    std::unordered_map<int,char> num_to_code_map_;
    std::unordered_map<char,int> code_to_num_map_;

};