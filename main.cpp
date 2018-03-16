#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> readToggleSequence(int m)
{
	vector<int> toggleSequence;
	for(int i=0;i<m;i++)
	{
		int deviceIndex;
		cin >> deviceIndex;
		toggleSequence.push_back(deviceIndex);
	}
	return toggleSequence;
}

int main()
{
	int n,m,c;
	int counter=1;
	while(1)
	{
		cin >> n >> m >> c;
		if((n==0)&&(m==0)&&(c==0))
			return 0;

		int*devicePowers=new int [n];
		bool* deviceStates=new bool [n];
		for(int i=0;i<n;i++)
			deviceStates[i]=false;

		for(int i=0;i<n;i++)
			cin >> devicePowers[i];

		int usedPower = 0;

		vector<int> toggleSequence = readToggleSequence(m);

		int maxofusedpower=0;
		for(int i=0;i<m;i++)
		{
			int deviceIndex = toggleSequence[i];
			deviceStates[deviceIndex-1] = !deviceStates[deviceIndex-1];
			if(deviceStates[deviceIndex-1])
				usedPower=usedPower+devicePowers[deviceIndex-1];
			else
				usedPower=usedPower-devicePowers[deviceIndex-1];
			if(usedPower>maxofusedpower)
				maxofusedpower=usedPower;
		}
		if(maxofusedpower>c)
		{
			printf("Sequence %d\nFuse was blown.\n\n",counter);
			counter++;
		}
		else
		{
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",counter,maxofusedpower);
			counter++;
		}
	}
}
