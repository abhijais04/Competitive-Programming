#include<iostream>
using namespace std;
char ch[1000];
char ch2[1000];
int solve()
{
	cin >> ch;
	cin >> ch2;
	int l1 = 0, l2 = 0;
	while (ch[l1] != '\0')
		l1++;
	while (ch2[l2] != '\0')
		l2++;
	if (l1 != l2)
		return false;
	for (int i = 0; i < l1; i++)
	{
		for (int j = i + 1; j < l1; j++)
		{
			if (ch[i] > ch[j])
			{
				char tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	int pt = 0;
	while (pt<l1 && ch[pt] == '0')
		pt++;
	if (pt < l1)
	{
		char tmp = ch[0];
		ch[0] = ch[pt];
		ch[pt] = tmp;
	}

	for (int i = 0; i < l1; i++)
	{
		if (ch[i] != ch2[i])
			return false;
	}
	return true;
}
int main()
{
	int t=1;
	//cin >> t;
	while (t--)
	{
		if (solve())
			cout << "OK\n";
		else
			cout << "WRONG_ANSWER\n";
	}
}