#include"iomanip"
#include"iostream"
#include"ip_calc.h"
using namespace std;
void write_line(const char*header,const unsigned int&value){
    cout<<setw(24)<<header
        <<setw(24)<<get_IP_as_string_dec(value)
        <<'\t'<<get_IP_as_string_bin(value)
        <<endl;
    }
int main(){
    setlocale(LC_ALL,"rus");
    ip_calc Host_adr;
    /* * * ВВОД * * */
    string buffer;
    cout<<endl
        <<"Введите адрес IP по октетам (0 - 255)"<<endl;
    for(unsigned short i=1;i<=4;){
        cout<<"\t№"<<i<<": ";
        cin>>buffer;
        if(Host_adr.set_address(buffer,i))i++;
        else cout<<"(!) неверное значение, попробуйте ещё раз"<<endl;
        }
    while(true){
        cout<<"Введите длину маски (1 - 32): ";
        cin>>buffer;
        if(Host_adr.set_netmask(buffer))break;
        else cout<<"(!) неверное значение, попробуйте ещё раз"<<endl;
        }
    /* * * ВЫВОД * * */
    write_line("Address:",Host_adr.get_address());
    write_line("Netmask:",Host_adr.get_netmask());
    vector<unsigned int>result=Host_adr.calculate();
    const char*header[]={"Wildcard:","Network:","Broadcast:","HostMIN:","HostMAX:"};
    for(size_t i=0;i<result.size();i++)
        write_line(header[i],result.at(i));
    return EXIT_SUCCESS;
    }
