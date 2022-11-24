#include"ip_calc.h"
#include"iostream"
#include"iomanip"
using namespace std;

int main()
{
    int n=11;
    ip_calc UT;
    std::string mask_test [n]= {
        "1",
        "0",
        "-1",
        "32",
        "/n",
        "33",
        "-99999999999999999999999999999999999999999999",
        "9999999999999999999999999999999999999999999999999999999999999999999999999999",
        "\t",
        "256",
        "mmmmm"
     };
   cout<<"Netmask Test";
   cout<<"\n";
     for(int i=0;i<n;i++)
    {
      if ((UT.set_netmask(mask_test[i]))==false)
      cout<<"error "<<mask_test[i]<<"\n";
      else
      cout<<"correct "<<mask_test[i]<<"\n";
    }

   cout<<"\n";
   cout<<"Address Test \n";
    for(int i=0;i<n;i++)
    {
       if (UT.validate(mask_test[i],0,255))
       cout<<"correct "<<mask_test[i]<<"\n";
       else
       cout<<"error "<<mask_test[i]<<"\n";
    }
    getchar();
   return EXIT_SUCCESS;
}

