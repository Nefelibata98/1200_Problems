#### 001 在一个数组中寻找最大值和最小值所需要进行比较的次数

每次取数组中的两个元素比较，大的和 max 比较，小的和 min 比较。

如果数组总数为奇数，max 和 min 的起始值设置为数组第一个元素；如果数组总数为偶数，将 max 和 min 设置为数组前两个元素（大的是 max 小的是 min）

```cpp
#include<bits/stdc++.h>
#include<limits.h>

using namespace std;

// 注意初始化时的逻辑是和 for 循环中的逻辑是不同的
// 要么这样初始化，要么单独写一个赋值
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
		cout << "没有有效输入" << endl;
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
```

参考：https://blog.csdn.net/cloudblaze/article/details/75087408