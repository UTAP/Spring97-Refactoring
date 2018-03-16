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

int simulateDeviceToggles(int n, int* devicePowers, vector<int> toggleSequence)
{
	int maxPowerUsed = 0;
	int usedPower = 0;
	int m = toggleSequence.size();

	bool* deviceStates = new bool[n];
	for(int i = 0; i < n; i++)
		deviceStates[i] = false;

	for(int i = 0; i < m; i++)
	{
		int deviceIndex = toggleSequence[i];
		deviceStates[deviceIndex-1] = !deviceStates[deviceIndex-1];
		if(deviceStates[deviceIndex-1])
			usedPower = usedPower + devicePowers[deviceIndex-1];
		else
			usedPower = usedPower - devicePowers[deviceIndex-1];
		if(usedPower > maxPowerUsed)
			maxPowerUsed = usedPower;
	}

	return maxPowerUsed;
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
		for(int i=0;i<n;i++)
			cin >> devicePowers[i];

		vector<int> toggleSequence = readToggleSequence(m);

		int maxPowerUsed = simulateDeviceToggles(n, devicePowers, toggleSequence);

		if(maxPowerUsed>c)
		{
			printf("Sequence %d\nFuse was blown.\n\n",counter);
			counter++;
		}
		else
		{
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",counter,maxPowerUsed);
			counter++;
		}
	}
}
