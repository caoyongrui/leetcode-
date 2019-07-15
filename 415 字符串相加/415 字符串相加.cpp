/*
给定两个字符串形式的非负整数?num1 和num2?，计算它们的和。

注意：

num1 和num2?的长度都小于 5100.
num1 和num2 都只包含数字?0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库，?也不能直接将输入的字符串转换为整数形式。
*/

#include <iostream>
#include <string>
using namespace std;

string addStrings(string num1, string num2)
{
	string res;
	int len1 = num1.length();
	int len2 = num2.length();
	int maxLen = len1 > len2 ? len1 : len2;
	while (len1 < maxLen)
	{
		num1 = '0' + num1;
		len1++;
	}
	while (len2 < maxLen)
	{
		num2 = '0' + num2;
		len2++;
	}
	int temp = 0;
	int num = 0;
	for (int i = maxLen - 1; i >= 0; i--)
	{
		num = (num1[i] - '0') + (num2[i] - '0') + temp;
		temp = num / 10;
		res = to_string(num % 10) + res;
	}
	if (temp)
		res = '1' + res;
	return res;
}

int main()
{
	string num1 = "";
	string num2 = "";
	string res = addStrings(num1, num2);
	cout << res << endl;

	system("pause");
	return 0;
}