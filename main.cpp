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
		bool* deviceStates=new bool [n];
		int deviceIndex;
		for(int i=0;i<n;i++)
			deviceStates[i]=0;

		for(int i=0;i<n;i++)
			cin >> devicePowers[i];

		for(int i=0;i<m;i++)
		{
			cin >> deviceIndex;
			if(!deviceStates[deviceIndex-1])
			{
				deviceStates[deviceIndex-1] = true;
				usedpower=usedpower+devicePowers[deviceIndex-1];

			}
			else if(deviceStates[deviceIndex-1])
			{
				deviceStates[deviceIndex-1] = false;
				usedpower=usedpower-devicePowers[deviceIndex-1];
			}
			if(usedpower>maxofusedpower)
				maxofusedpower=usedpower;
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
