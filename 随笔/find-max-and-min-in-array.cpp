#include<bits/stdc++.h>
#include<limits.h>

using namespace std;

// ע���ʼ��ʱ���߼��Ǻ� for ѭ���е��߼��ǲ�ͬ��
// Ҫô������ʼ����Ҫô����дһ����ֵ
int Max = INT_MIN;
int Min = INT_MAX;

void SetMaxAndMin(int a, int b)
{
	int big, small;
	if (a > b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}

	Max = Max > big ? Max : big;
	Min = Min < small ? Min : small;
}

int main(void)
{
	int N;
	vector<int> v;
	cin >> N;
	while (N--)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int begin = 1;

	if (v.size() == 0)
		cout << "û����Ч����" << endl;
	else if (v.size() == 1)
		Max = Min = v[0];
	else if (v.size() % 2 != 0)
	{
		Max = Min = v[0];
		begin = 1;
	}
	else
	{
		SetMaxAndMin(v[0], v[1]);
		begin = 2;
	}

	for (int i = begin; i < v.size(); i += 2)
	{
		SetMaxAndMin(v[i], v[i + 1]);
	}

	cout << "max: " << Max << endl
		<< "min: " << Min << endl;

	return 0;
}