/*
����һ���Ѱ�����������?���������飬�ҵ�������ʹ���������֮�͵���Ŀ������

����Ӧ�÷����������±�ֵ index1 �� index2������ index1?����С��?index2��

˵��:

���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:

����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> res;
	bool state = false;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				res.push_back(i + 1);
				res.push_back(j + 1);
				state = true;
				break;
			}
		}
		if (state == true)
			break;
	}
	return res;
}

//���ֲ���
vector<int> twoSum1(vector<int>& numbers, int target)
{
	vector<int> res;
	bool state = false;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		int k = i + 1;
		int j = numbers.size() - 1;
		while (k <= j)
		{
			int mid = (k + j) / 2;
			if (numbers[mid] + numbers[i] == target)
			{
				res.push_back(i + 1);
				res.push_back(mid + 1);
				state = true;
				break;
			}
			else if (numbers[mid] + numbers[i] < target)
			{
				k = mid + 1;
			}
			else
				j = mid - 1;
		}
		if (state == true)
			break;
	}
	return res;
}

int main()
{
	vector<int> numbers;
	int n;
	while (cin >> n)
	{
		numbers.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int target;
	cin >> target;
	vector<int> res = twoSum1(numbers, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}