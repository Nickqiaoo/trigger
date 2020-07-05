#include "invite_module.h"
#include <string>

InviteModule::InviteModule(){
    num_to_code_map_={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'},{10,'a'},
    {11,'b'},{12,'c'},{13,'d'},{14,'e'},{15,'f'},{16,'g'},{17,'h'},{18,'i'},{19,'j'},{20,'k'},
    {21,'l'},{22,'m'},{23,'n'},{24,'o'},{25,'p'},{26,'q'},{27,'r'},{28,'s'},{29,'t'},{30,'u'},
    {31,'v'},{32,'w'},{33,'x'},{34,'y'},{35,'z'},{36,'A'},{37,'B'},{38,'C'},{39,'D'},{40,'E'},
    {41,'F'},{42,'G'},{43,'H'},{44,'I'},{45,'J'},{46,'K'},{47,'L'},{48,'M'},{49,'N'},{50,'O'},
    {51,'P'},{52,'Q'},{53,'R'},{54,'S'},{55,'T'},{56,'U'},{57,'V'},{58,'W'},{59,'X'},{60,'Y'},{61,'Z'},
    };

    for(auto it = num_to_code_map_.begin(); it != num_to_code_map_.end(); it++){
        code_to_num_map_[it->second] = it->first;
    }
}

InviteModule::~InviteModule(){}

std::string InviteModule::convertRoleIdToCode(int64_t roleId){

    std::string roleIdStr = std::to_string(roleId);
    std::reverse(roleIdStr.begin(),roleIdStr.end());
    roleId = atoll(roleIdStr.c_str()) << 18;

    std::string code;
    do{
		code.insert(code.begin(), num_to_code_map_[roleId % 62]);
		roleId = roleId / 62;
	}while(roleId != 0);
    return code;
}

int64_t InviteModule::convertCodeToRoleId(std::string inviteCode){
    int k = 0;
    int64_t roleId = 0;
    for(auto it = inviteCode.rbegin(); it!=inviteCode.rend(); it++){
        roleId += code_to_num_map_[(*it)] * pow(62, k);
        k++;
    }
    
    roleId = roleId>>18;
    std::string roleIdStr = std::to_string(roleId);
    std::reverse(roleIdStr.begin(),roleIdStr.end());
    roleId = atoll(roleIdStr.c_str());

    return roleId;
}

