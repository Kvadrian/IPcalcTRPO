#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
using namespace std;

short int A[4], M[32], B[4][8], Network[4][8] , Hostmin[4][8], Hostmax[4][8], Broadcast[4][8], Wildcard[4][8];


int mask=0,i,j,k;

int main()


{
//	memset(M,0,sizeof(int)*32);
	
	
	for (i=0;i<4;i++)
		{
		/*	scanf("%[0-9]",&A[i]);
			if (scanf("%d", &A[i]) != 1)
			 {   scanf("%*s");
			 	cout<<"input coorect format";
			 	i--;
			 	continue;
			}*/
      		 while (!(cin >> A[i]))
			   {        
        			cout << "error\n";          
        			cin.clear();                
        			fflush(stdin);              
    			}
			if ((A[i]>=0)&&(A[i]<256))
			continue;
			else
			{
			cout<<"input coorect format";
			i--;
			}
			   
		}
		
	for (i=0;i<4;i++)
	cout<<A[i]<<".";
			cout<<"\t";
	
	      		 while (!(cin >> mask)||(mask<1)||(mask>32))
			   {      
        			cout << "error\n";          
        			cin.clear();                
        			fflush(stdin);             
    			}
    			
		
		cout<<"\t"<<mask;
		for(i=0;i<mask;i++)
		M[i]=1;
			/*	for(i=0;i<32;i++)
		cout<<M[i];*/
		for(i=31;i>(mask-1);i--)
		M[i]=0;
		cout<<"\t";
		for(i=0;i<32;i++)
		cout<<M[i];
		
		for (i=0;i<4;i++)
			{
				for(j=7;j>-1;j--)
				{	if(A[i]==0)
				break;
				B[i][j]=A[i]%2;
					A[i]=A[i]/2;
				}
		}
					
						cout<<"\n";
						cout<<"Host: ";
						for(i=0;i<4;i++)
						{	
						for(j=0;j<8;j++)
							cout<<B[i][j];
							cout<<".";
						}
				cout<<"\n";
		for (k=0,i=0;i<4;i++)
		{	for(j=0;j<8;j++)
			{Network[i][j]=B[i][j]&M[k];
			Wildcard[i][j]=M[k]^1;
			Broadcast[i][j]=Network[i][j] | Wildcard[i][j] ;
			Hostmin[i][j]=Network[i][j];
			Hostmax[i][j]=Broadcast[i][j];
			
			k++;}
		}
		Hostmax[3][7]=Wildcard[3][7]^Broadcast[3][7];
		Hostmin[3][7]=Network[3][7]|1;
						cout<<"\n";
						cout<<"Network: ";
								for(i=0;i<4;i++)
						{	
						for(j=0;j<8;j++)
							cout<<Network[i][j];
							cout<<".";
						}
										cout<<"\n";
					cout<<"Wildcard: ";
									for(i=0;i<4;i++)
						{	
						for(j=0;j<8;j++)
							cout<<Wildcard[i][j];
							cout<<".";
						}
						
							cout<<"\n";
							cout<<"Broadcast: ";
						for(i=0;i<4;i++)
						{	
						for(j=0;j<8;j++)
							cout<<Broadcast[i][j];
							cout<<".";
						}
							cout<<"\n";
							cout<<"Hostmin: ";
						for(i=0;i<4;i++)
						{
						for(j=0;j<8;j++)
							cout<<Hostmin[i][j];
								cout<<".";
						}
						cout<<"\n";
						cout<<"Hostmax: ";
						for(i=0;i<4;i++)
						{	
						for(j=0;j<8;j++)
							cout<<Hostmax[i][j];
							cout<<".";
						}
						cout<<"TESTGIT";
						
	system("pause");
	return 0;
}
