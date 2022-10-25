#include <bits/stdc++.h>
#include "ckollib.h"

using namespace std;


int licz[40], num1, num2, cn1, cn2;

void rozklad(int a)
{
	int idx = 0;
	
	while(a)
	{
		licz[idx++] += (a&1);
		a >>= 1;
	}
}

int main()
{	
	//zbieranie kart
	int k = karta();
	
	num1 = k;
	
	while((k == num1) && k)
	{
		rozklad(k);
		++cn1;
		
		k = karta();
	}
	
	if(k == 0)
		odpowiedz(num1);
		
	num2 = k;
	
	while(k)
	{
		if(k == num1)
			++cn1;
		else if(k == num2)
			++cn2;
			
		rozklad(k);
		
		k = karta();
	}
	//
	
	//obliczanie wyniku
	int mod = max(cn1, cn2);
	int odp = 0;
	int pot = 1;
	
	for (int i = 0; i < 40; ++i)
	{
		licz[i] %= mod;
		
		if(licz[i])
			odp += pot;
		
		pot <<= 1;
	}
	
	odpowiedz(odp);
	//
	return 0;
}