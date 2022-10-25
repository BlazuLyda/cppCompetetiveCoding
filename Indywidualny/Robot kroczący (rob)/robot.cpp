#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, x, y;
vector<int> nums[2];
bitset<1000000> las, cur, mat, tmp;

bool plecak(int z, int c)
{
	if(nums[z].size() == 0)	
		return (c == 0);
	
	sort(nums[z].begin(), nums[z].end());
	
	int last = nums[z][0], cnt = 0;
	vector<pair<int,int>> items;
	
	for(auto i : nums[z])
	{
		if(i != last)
		{
			items.push_back({last, cnt});
			
			cnt = 1;
		}
		else
			++cnt;
			
		last = i;
	}
	
	items.push_back({last, cnt}); //do poprzedniej pętli
	
	las.reset();
	las[500000] = 1;
	
	for (auto i : items)
	{
		cur.reset();
		mat.reset();
		
		//printf("\tdlugosc:%d liczba:%d\n", i.ff, i.ss);
		
		for (int j = -i.ss; j <= i.ss; j += 2) //tworzenie matrycy; pętla łącznie jest robiona n razy: O(n)
		{
			mat[500000 + (j * i.ff)] = 1;
		}
		
		for (int j = 0; j <= n; ++j) //przykładanie matrycy
		{
			if(las[j + 500000])
				cur = (cur | (mat << j)); //czas stały: O(1)
				
			if(las[-j + 500000])
				cur = (cur | (mat >> j)); //czas stały: O(1)
		}
		
		/*
		printf("tablica:\n");
		for (int j = -n; j <= n; ++j) //wypisanie liczb, które można stworzyć
		{
			if(cur[j + 500000])
				printf("%d, ", j);
		}
		printf("\n\n");
		*/
		
		las = cur;
	}
	
	return las[c + 500000];
}

int main()
{
	scanf("%d", &n);
	
	int len = 0, dir = 1, a;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		
		if(a)
		{
			if(len)
				nums[dir].push_back(len);
				
			dir ^= 1;
			len = 0;
		}
		else
			++len;
	}
	
	if(len)
			nums[dir].push_back(len);
	
	scanf("%d %d", &x, &y);
	
	bool wyn;
	
	wyn = plecak(0, x);
	
	wyn = wyn && plecak(1, y);
	
	if(wyn)
		printf("TAK\n");
	else
		printf("NIE\n");
	
	return 0;
}