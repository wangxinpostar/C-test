#include<iostream>
using namespace std;
#include<iomanip>
 
int main()
{
	int n, m;
	cin >> n >> m;
 
	double dd[21][21] = { 0.0 };
	double P = 1.0 / n;
 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1)
			{
				dd[i][j] = 1.0;
				for (int k = 1; k < j; k++)
				{
					dd[i][j] *= P;
				}
			}
			else
			{
				dd[i][j] = dd[i][j - 1] * (i * P) + dd[i - 1][j - 1] * ((n - (i - 1)) * P);
			}
		}
	}
 
	cout << fixed << setprecision(4);
 
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		cout << dd[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
 
	cout << dd[n][m];
 
	return 0;
}