
[OJ ����](https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false)

```cpp
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int n;
    vector<int> v;
    while (cin >> n)
    {
        v.resize(3 * n);
        for (int i = 0; i < 3 * n; i++)
        {
            cin >> v[i];
        }

        //����
        sort(v.begin(), v.end());

        // sumMax ����������Ӧ���㹻��
        size_t sumMax = 0;
        // ÿ�����СԪ�ش����� [0, n - 1] �л��
        // [n, 3n - 1] ÿ����ȡ��һ�����м�Ԫ�أ�
        for (int i = n; i < 3 * n - 1; i += 2)
        {
            sumMax += v[i];
        }

        cout << sumMax << endl;
    }

    return 0;
}
```