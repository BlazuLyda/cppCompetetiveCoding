#include <stdio.h>
#include <random>

long long randint(long long a, long long b)
{
	return a + rand() % (b-a+1);
}

unsigned randomize(unsigned x)
{
	for(unsigned i=0;i<100000;++i)
	{
		std::mt19937 gen(x);
		unsigned tmp=std::uniform_int_distribution<unsigned>(0,4294967295)(gen);
		x=(tmp^(tmp>>26)^x)&(67108863);
	}
	x^=12404060;
	return x;
}

int main()
{
	srand(199999);
	
	long long max = 0, may = 0, x, y;
	
	while(true)
	{
		x = randint(0, 67108863);
		y = randomize(x);
		
		if(y > may)
		{
			max = x;
			may = y;
		}
		
		printf("%lld %lld\n", max, may);
	}
	
}
