/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。



示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"
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