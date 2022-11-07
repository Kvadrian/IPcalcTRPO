#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
using namespace std;

short int A[4], M[32], B[4][8], Network[4][9] , Hostmin[4][9], Hostmax[4][9], Broadcast[4][9], Wildcard[4][9];


int mask=0,i,j,k;

int main()


{
//	memset(M,0,sizeof(int)*32);
	cout<<"\n"<<"Please, input octets. Correct value is between 0 and 255"<<"\n";
	for (i=0;i<4;i++)
		{
			cout<<"Now input "<<i+1<<" octet"<<"\n";
      		 while (!(cin >> A[i]))
			   {        
        			cout << "input coorect format"<<"\n";          
        			cin.clear();                
        			fflush(stdin);              
    			}
			if ((A[i]>=0)&&(A[i]<256))
				continue;
			else
				{
					cout<<"input coorect format"<<"\n";
					i--;
				}
			   
		}
		
	cout<<"Now input mask, Correct value is between 0 and 32" <<"\n";
	
	while (!(cin >> mask)||(mask<1)||(mask>32))
		{      
        	cout << "input coorect format"<<"\n";          
        	cin.clear();                
        	fflush(stdin);             
    	}
    	
    			
	for (i=0;i<4;i++)
		cout<<A[i]<<".";
		
	cout<<"\t";
	
	for(i=0;i<mask;i++)
	M[i]=1;

	for(i=31;i>(mask-1);i--)
	M[i]=0;

	cout<<"\n";
	cout<<"Host: \t \t";
	for (i=0;i<4;i++)
	cout<<A[i]<<".";
	
	cout<<"\t";
			
	for (i=0;i<4;i++)
		{
			for(j=7;j>-1;j--)
				{	
					if(A[i]==0)
						break;
					B[i][j]=A[i]%2;
					A[i]=A[i]/2;
				}
		}
					
					
	for(i=0;i<4;i++)
		{	
			for(j=0;j<8;j++)
				cout<<B[i][j];
			cout<<".";
		}
		
	cout<<"\t";
	cout<<"\nMask: \t \t"<<mask;
	
	cout<<"\n";
	
	for (k=0,i=0;i<4;i++)
		{	
			for(j=0;j<8;j++)
			{
				Network[i][j]=B[i][j]&M[k];
				Wildcard[i][j]=M[k]^1;
				Broadcast[i][j]=Network[i][j] | Wildcard[i][j] ;
				Hostmin[i][j]=Network[i][j];
				Hostmax[i][j]=Broadcast[i][j];
				k++;
			}
		}
	Hostmax[3][7]=Wildcard[3][7]^Broadcast[3][7];
	Hostmin[3][7]=Network[3][7]|1;
		
	for (i=0;i<4;i++)
		{	
			for(j=7;j>=0;j--)
				{
				//cout<<" "<<Network[i][8]<<" ";
					Network[i][8]=Network[i][8]+Network[i][j]*pow(2,(7-j));
					Wildcard[i][8]=Wildcard[i][8]+Wildcard[i][j]*pow(2,(7-j));
					Broadcast[i][8]=Broadcast[i][8]+Broadcast[i][j]*pow(2,(7-j));
					Hostmin[i][8]=Hostmin[i][8]+Hostmin[i][j]*pow(2,(7-j));
					Hostmax[i][8]=Hostmax[i][8]+Hostmax[i][j]*pow(2,(7-j));				
				}
			
		}
		
		
	
	cout<<"\n";
	cout<<"Network: "<<"\t";
	
	for (i=0,j=8;i<4;i++)
		cout<<Network[i][j]<<".";
	cout<<"\t";
	
	for(i=0;i<4;i++)
		{	
			for(j=0;j<8;j++)
				cout<<Network[i][j];
			cout<<".";
		}
		
		
						
	cout<<"\n";
	cout<<"Wildcard: "<<"\t";
	
	for (i=0,j=8;i<4;i++)
		cout<<Wildcard[i][j]<<".";
	cout<<"\t";						
	for(i=0;i<4;i++)
		{	
			for(j=0;j<8;j++)
				cout<<Wildcard[i][j];
			cout<<".";
		}
						
	
					
	cout<<"\n";
	cout<<"Broadcast: "<<"\t";
	
	for (i=0,j=8;i<4;i++)
		cout<<Broadcast[i][j]<<".";
	cout<<"\t";						
	for(i=0;i<4;i++)
		{	
			for(j=0;j<8;j++)
				cout<<Broadcast[i][j];
			cout<<".";
		}
						

						
	cout<<"\n";
	cout<<"Hostmin: "<<"\t";
	
	for (i=0,j=8;i<4;i++)
		cout<<Hostmin[i][j]<<".";
	cout<<"\t";	
	
						
	for(i=0;i<4;i++)
		{	
			for(j=0;j<8;j++)
				cout<<Hostmin[i][j];
			cout<<".";
		}
						

						
	cout<<"\n";
	cout<<"Hostmax: "<<"\t";
						
	for (i=0,j=8;i<4;i++)
		cout<<Hostmax[i][j]<<".";
	cout<<"\t";						
	for(i=0;i<4;i++)
		{	
			for(j=0;j<8;j++)
				cout<<Hostmax[i][j];
			cout<<".";
		}
						
	cout<<"\n";					
						
	system("pause");
	return 0;
}