#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int checkFuse(int m, int c, vector<int> power, vector<bool> situation)
{
	int usedpower=0,maxofusedpower=0;
	int n = power.size();
	vector<int> toggleSequence;
	for(int i=0;i<m;i++)
	{
		int number;
		cin >> number;
		toggleSequence.push_back(number);
	}
	for(int i=0;i<m;i++)
	{
		int number = toggleSequence[i];
		situation[number-1]= !situation[number-1];
		if(situation[number-1])
			usedpower+=power[number-1];
		else
			usedpower-=power[number-1];
		if(usedpower>maxofusedpower)
			maxofusedpower=usedpower;
		if(usedpower>c)
			return -1;
	}
	return maxofusedpower;
}

void powerSimulator()
{
	int n,m,c;
	int counter=1;

	while(true)
	{
		cin >> n >> m >> c;
		if((n==0)&&(m==0)&&(c==0))
			return;

		vector<int> power;
		for(int i=0;i<n;i++){
			int p;
			cin>>p;
			power.push_back(p);
		}

		vector<bool> situation;
		for(int i=0;i<n;i++)
			situation.push_back(0);
		int maxofusedpower = checkFuse(m, c, power, situation);
		if(maxofusedpower == -1)
		{
			cout<<"Sequence "<<counter<<"\nFuse was blown.\n\n";
			counter++;
		}
		else
		{
			cout<<"Sequence "<<counter<<"\nFuse was not blown.\nMaximal power consumption was "<<maxofusedpower<<" amperes.\n\n";
			counter++;
		}
	}
}
int main()
{
	powerSimulator();
}
