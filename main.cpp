#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,c;
	int i,j,counter=1;
	int usedpower=0,maxofusedpower=0;
	while(1)
	{
		cin >> n >> m >> c;
		if((n==0)&&(m==0)&&(c==0))
			return 0;

		int*power=new int [n];
		int*situation=new int [n];
		int number;
		for(i=0;i<n;i++)
			situation[i]=0;

		for(i=0;i<n;i++)
			cin >> power[i];

		for(i=1;i<(m+1);i++)
		{
			cin >> number;
			for(j=1;j<(n+1);j++)
			{
				if((number==j)&&(situation[j-1]==0))
				{
					situation[j-1]=1;
					usedpower=usedpower+power[j-1];
					if(usedpower>maxofusedpower)
						maxofusedpower=usedpower;
					break;
				}
				if((number==j)&&(situation[j-1]==1))
				{
					situation[j-1]=0;
					usedpower=usedpower-power[j-1];
					if(usedpower>maxofusedpower)
						maxofusedpower=usedpower;
					break;
				}
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
