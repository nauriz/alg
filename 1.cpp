#include <iostream> 
#define word unsigned int
using namespace std;

int		flag[11];								/// array of flags
word	c[11][11];
word	l[11];



int min(int n)
{
	int i, result;
	for(i=0;i<n;i++)
	{
		if(!(flag[i]))
			result=i;
	}
	for(i=0;i<n;i++)
	{
		if((l[result]>l[i])&&(!flag[i]))
			result=i;
	}
	return result;
}



word minim(word x, word y)
{
	if(x<y)
		return x;
	return y;
}

int main()
{
	int n;										/// number of tops
	int p;
	int xn;
	int xk;
	char s[80];									/// buffer
	char path[80][11];							/// array for paths between points

	cout<<"Input number of tops: "; cin>> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			c[i][j] = 0;
	}
	for( int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			cout<<"Length from  x"<< i+1 <<" to x"<<j+1<<":";
			cin>> c[i][j];
		}
	}
	cout<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\tX"<<i+1;
	}
	cout<<endl;
	for(int i = 0; i < n; i++)
	{
		printf("X%d",i+1);
		for(int j = 0; j < n; j++)
		{
			printf("\t%d",c[i][j]);
			c[j][i] = c[i][j];
		}
		cout<<endl<<endl;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(c[i][j] == 0)
				c[i][j] = 65535;
	}

	cout<<"Input start point: X";
	cin>> xn;
	cout<<"Input end point: X";
	cin>> xk;
	xk--;
	xn--;

	if(xn == xk)
	{
		cout<<"Start and end points are the same."<<endl;
		getchar();
		getchar();
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		flag[i] = 0;
		l[i] = 65535;
	}

	l[xn] = 0;
	flag[xn] = 1;
	p = xn;
	itoa(xn+1,s,10);

	for(int i = 1; i <= n; i++)
	{
		strcpy(path[i],"X");
		strcat(path[i],s);
	}

	do
	{
		for(int i = 0; i < n; i++)
		{
			if((c[p][i] != 65535) && (!flag[i]) && (i != p))
			{
				if(l[i] > (l[p]+c[p][i]))
				{
					itoa(i+1,s,10);
					strcpy(path[i+1],path[p+1]);
					strcat(path[i+1],"-X");
					strcat(path[i+1],s);
				}
				l[i] = minim(l[i], l[p]+c[p][i]);
			}
		}
		p = min(n);
		flag[p] = 1;
	}
	while(p != xk);
	if(l[p] != 65535)
	{
		cout<<"\nPath between points: "<<path[p+1]<<endl;
		cout<<"\tpath length: "<<l[p]<<endl;
	}
	else
		cout<<"Path does not exist!"<<endl;

	getchar();
	getchar();
	return 0;
}