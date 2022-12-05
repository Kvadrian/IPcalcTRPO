#include "../IPCalcTRPO/Headers/ip_calc.h"
const std::string get_IP_as_string_bin(const unsigned int&IP){
    std::stringstream output;
    for(unsigned char i=32;i!=0;){
        output<<(1&(IP>>--i));
        if(i!=0&&i%8==0)output<<'.';
        }
    return output.str();
    }
const std::string get_IP_as_string_dec(const unsigned int&IP){
    std::stringstream output;
    for(unsigned char i=4;i!=0;){
        output<<(0xff&(IP>>(8*--i)));
        if(i!=0)output<<'.';
        }
    return output.str();
    }
ip_calc::ip_calc(){IP={0,0};}
ip_calc::ip_calc(const unsigned int&address,const unsigned int&netmask){IP={address,netmask};}
std::vector<unsigned int>ip_calc::calculate(){
    std::vector<unsigned int>result;
    result.push_back(calculate_wildcard());
    result.push_back(calculate_network());
    result.push_back(calculate_broadcast(result.at(0),result.at(1)));
    result.push_back(calculate_hostmin(result.at(1)));
    result.push_back(calculate_hostmax(result.at(0),result.at(2)));
    return result;
    }
unsigned int ip_calc::calculate_broadcast(const unsigned int&network,const unsigned int&wildcard){return network|wildcard;}
unsigned int ip_calc::calculate_hostmax(const unsigned int&wildcard,const unsigned int&broadcast){
    return (wildcard&1)==(broadcast&1)?
           broadcast&(~static_cast<unsigned int>(1)):
           broadcast|1;
    }
unsigned int ip_calc::calculate_hostmin(const unsigned int&network){return network|1;}
unsigned int ip_calc::calculate_network(){return IP.address&IP.netmask;}
unsigned int ip_calc::calculate_wildcard(){return ~IP.netmask;}
const unsigned int&ip_calc::get_address(){return IP.address;}
const unsigned int&ip_calc::get_netmask(){return IP.netmask;}
void ip_calc::reset_address(const unsigned char&pos){
    if(pos>0&&pos<=4)IP.address&=~((static_cast<unsigned int>(0xff))<<(8*(4-pos)));
    }
void ip_calc::reset_netmask(){IP.netmask=0;}
void ip_calc::set_address(const unsigned char&octet,const unsigned char&pos){
    if(pos>0&&pos<=4){
        reset_address(pos);
        IP.address|=((static_cast<unsigned int>(octet))<<(8*(4-pos)));
    }}
bool ip_calc::set_address(const std::string&octet,const unsigned char&pos){
    if(pos>0&&pos<=4){
        if(!validate(octet,0,255))return false;
        else{
            set_address(static_cast<unsigned char>(std::stoi(octet)),pos);
            return true;
        }}
    else return false;
    }
void ip_calc::set_netmask(const unsigned char&length){
    if(length>0&&length<=32){
        reset_netmask();
        for(unsigned char i=length;i!=0;i--)
            IP.netmask|=static_cast<unsigned int>(1)<<(32-i);
    }}
bool ip_calc::set_netmask(const std::string&length){
    if(!validate(length,1,32))return false;
    else{
        set_netmask(static_cast<unsigned char>(std::stoi(length)));
        return true;
    }}
bool ip_calc::validate(const std::string&number,const int&from,const int&till){
    for(auto i=number.size();i-->0;)
        if(number.at(i)<'0'||number.at(i)>'9')return false;
    try{
        int _number=std::stoi(number);
        return _number>=from&&_number<=till;
        }
    catch(...){
        return false;
    }}
