#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int wyn;
char flaga[6][9];

int A[26], B[26], C[26];
pair<int, char> ma[3], mb[3], mc[3];

void FindDom()
{
	for (int i = 0; i < 26; i++)
	{
		if(A[i] > ma[0].ff)
			ma[0] = {A[i], i};	
		
		if(B[i] > mb[0].ff)
			mb[0] = {B[i], i};
		
		if(C[i] > mc[0].ff)
			mc[0] = {C[i], i};	
		
		sort(ma, ma+3);
		sort(mb, mb+3);
		sort(mc, mc+3);
		
		A[i] = 0;
		B[i] = 0;
		C[i] = 0;
	}
	
	if(ma[0].ff == 0)
		ma[0].ss = -1;
	
	if(mb[0].ff == 0)
		mb[0].ss = -2;
	
	if(mc[0].ff == 0)
		mc[0].ss = -3;
}

void MixResults()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				//printf("A:(%d, %d)  B:(%d, %d)  C:(%d, %d)\n", ma[i].ff, ma[i].ss, mb[j].ff, mb[j].ss, mc[k].ff, mc[k].ss);
				
				if(ma[i].ss == mb[j].ss || mc[k].ss == mb[j].ss)
					continue;
				
				wyn = max(wyn, ma[i].ff + mb[j].ff + mc[k].ff);
			}
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		ma[i].ff = 0;
		mb[i].ff = 0;
		mc[i].ff = 0;
	}
}

int main()
{
	//input
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
			scanf(" %c", &flaga[i][j]);	
	}
	//
	
	//horizontal stripes
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 9; j++)
			A[flaga[i][j] - 'A']++;
	}
	
	for (int i = 2; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
			B[flaga[i][j] - 'A']++;
	}
	
	for (int i = 4; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
			C[flaga[i][j] - 'A']++;
	}
	
	FindDom();
	
	MixResults();
	//
	
	//vertical stripes
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 6; i++)
			A[flaga[i][j] - 'A']++;	
	}
	
	for (int j = 3; j < 6; j++)
	{
		for (int i = 0; i < 6; i++)
			B[flaga[i][j] - 'A']++;
	}
	
	for (int j = 6; j < 9; j++)
	{
		for (int i = 0; i < 6; i++)
			C[flaga[i][j] - 'A']++;
	}
	
	FindDom();
	
	MixResults();
	//
	
	//print result
	printf("%d\n", 54 - wyn);
	//
	return 0;
}