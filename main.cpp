#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,c;
	int counter=1;
	int usedpower=0,maxofusedpower=0;
	while(1)
	{
		cin >> n >> m >> c;
		if((n==0)&&(m==0)&&(c==0))
			return 0;

		int*devicePowers=new int [n];
		int* deviceStates=new int [n];
		int deviceIndex;
		for(int i=0;i<n;i++)
			deviceStates[i]=0;

		for(int i=0;i<n;i++)
			cin >> devicePowers[i];

		for(int i=1;i<(m+1);i++)
		{
			cin >> deviceIndex;
			int j = deviceIndex;
			if(deviceStates[j-1]==0)
			{
				deviceStates[j-1]=1;
				usedpower=usedpower+devicePowers[j-1];
				if(usedpower>maxofusedpower)
					maxofusedpower=usedpower;
			}
			else if(deviceStates[j-1]==1)
			{
				deviceStates[j-1]=0;
				usedpower=usedpower-devicePowers[j-1];
				if(usedpower>maxofusedpower)
					maxofusedpower=usedpower;
			}
		}
		if(usedpower>c)
		{
			printf("Sequence %d\nFuse was blown.\n\n",counter);
			counter++;
			maxofusedpower=0;
		    usedpower=0;
			continue;
		}
		else
		{
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",counter,maxofusedpower);
			counter++;
			maxofusedpower=0;
		    usedpower=0;
			continue;
		}
	}
}
