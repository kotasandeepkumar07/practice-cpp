// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"


void main(int argc, char* argv[])
{

/************************************** 1. Selection Sort******************************************
	int a[6] = {4,2,0,8,9,6}; 
	for(int i=0; i<6; i++)
	{
		for(int j=i+1; j<7; j++)
		{
			if(a[j] > a[i])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i]= temp;	
			}	
		}
			cout<<a[i]<<endl;
	}


	
//************************************** 2. MULTI DIMENSIONAL ARRAYS ******************************************/

/*	int a[2][2]= {
					{1,2}, 
					{5,6}
				};
  
	for(int irow=0; irow<2; irow++)
	{
		for(int icolumn=0; icolumn<2; icolumn++)
		{
			cout<<a[irow][icolumn]<<" ";
		}
		cout<<endl;
*/




//****************************** 3. CHARCTER ARRAY ***********************************************



//	char a[] = { 'a', 'e', '\0'};
	char a[] = "ae";
	cout<<sizeof(a)<<endl;









/****************************** 4. NO BOUND  CHECKING ***********************************************
	int b= 10;
	int a[3];
	 a[0] = 1;
	 a[1] = 2;
	 a[2] = 3;

	cout<<"value of b before"<<b<<endl;
	a[3] = 12;
	cout<<"value of b after"<<b<<endl;
}
*/

}