/*
����������һ���������У��������е�������˳����б������õ���һ��������ǰ�������£�

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 ������  "one 1"  ("һ��һ") , �� 11��
11 ������ "two 1s" ("����һ"��, �� 21��
21 ������ "one 2",  "one 1" ��"һ����" ,  "һ��һ") , �� 1211��

����һ�������� n��1 �� n �� 30��������������еĵ� n �

ע�⣺����˳�򽫱�ʾΪһ���ַ�����



ʾ�� 1:

����: 1
���: "1"
ʾ�� 2:

����: 4
���: "1211"
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getSay(string s)
{
	vector<char> ch;
	vector<int> nums;
	int num = 0;
	for (int i = 0; i < s.length(); i++)
	{
		ch.push_back(s[i]);
		num++;
		int j = i + 1;
		while (j < s.length() && s[j] == s[i])
		{
			num++;
			j++;
		}
		nums.push_back(num);
		num = 0;
		i = j - 1;
	}
	string say;
	for (int i = 0; i < ch.size(); i++)
	{

		say = say + to_string(nums[i]) + ch[i];
	}
	return say;
}

string countAndSay(int n)
{
	string s = "1";
	for (int i = 1; i < n; i++)
	{
		s = getSay(s);
	}
	return s;
}

int main()
{
	string res = countAndSay(4);
	cout << res << endl;

	system("pause");
	return 0;
}