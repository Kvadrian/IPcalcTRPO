#ifndef IP_CALC_H
#define IP_CALC_H
#include"string"
#include"sstream"
#include"vector"
const std::string get_IP_as_string_bin(const unsigned int&IP);
const std::string get_IP_as_string_dec(const unsigned int&IP);
class ip_calc{
public:
    ip_calc();
    ip_calc(const unsigned int&address,const unsigned int&netmask);
    /* * * INTERFACE * * */
    std::vector<unsigned int>calculate();
    const unsigned int&get_address();
    const unsigned int&get_netmask();
    void set_address(const unsigned char&octet_from_0_to_255,const unsigned char&pos_from_1_to_4_where_1st_is_the_most_significant);
    bool set_address(const std::string&octet_from_0_to_255,const unsigned char&pos_from_1_to_4_where_1st_is_the_most_significant);
    void set_netmask(const unsigned char&length_from_1_to_32);
    bool set_netmask(const std::string&length_from_1_to_32);
private:
    /* * * FIELDS * * */
    struct{
        unsigned int address;
        unsigned int netmask;
        } IP;
    /* * * METHODS * * */
    unsigned int calculate_broadcast(const unsigned int&network,const unsigned int&wildcard);
    unsigned int calculate_hostmax(const unsigned int&wildcard,const unsigned int&broadcast);
    unsigned int calculate_hostmin(const unsigned int&network);
    unsigned int calculate_network();
    unsigned int calculate_wildcard();
    void reset_address(const unsigned char&pos);
    void reset_netmask();
    bool validate(const std::string&number,const int&from,const int&to);
    };
#endif // IP_CALC_H
