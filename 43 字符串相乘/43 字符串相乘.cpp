/*
给定两个以字符串形式表示的非负整数?num1?和?num2，返回?num1?和?num2?的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例?2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1?和?num2?的长度小于110。
num1 和?num2 只包含数字?0-9。
num1 和?num2?均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

static int SIZE = 4;

//格式化字符串函数
string formatNumber(string s, int len)
{
	while (s.length() < len)
	{
		s = "0" + s;
	}
	return s;
}

//处理数字串，分离出进位
//string数组第一个为原位，第二个为进位
vector<string> dealString(string s, int len)
{
	vector<string> res{s, "0"};
	if (len < s.length())
	{
		int t = s.length() - len;
		res[0] = s.substr(t);
		res[1] = s.substr(0, t);
	}
	else
	{
		for (int i = s.length(); i < len; i++)
		{
			s = "0" + s;
		}
		res[0] = s;
	}
	return res;
}

string addition(string s1, string s2)
{
	//返回的字符串
	string str = "";

	//两个字符串要相同
	int lenM = max(s1.length(), s2.length());
	s1 = formatNumber(s1, lenM);
	s2 = formatNumber(s2, lenM);

	//按位加，进位存储在flag中
	int flag = 0;

	for (int i = lenM - 1; i >= 0; i--)
	{
		int t = (s1[i] - '0') + (s2[i] - '0') + flag;

		if (t > 9)
		{
			flag = 1;
			t -= 10;
		}
		else
			flag = 0;

		str = to_string(t) + str;
	}
	if (flag)
	{
		str = to_string(flag) + str;
	}
	return str;
}

string multiply(string num1, string num2)
{
	if (!num1.length() || !num2.length())
	{
		return "";
	}
	if (num1 == "0" || num2 == "0")
	{
		return "0";
	}

	//结果字符串
	string str = "";

	//获得两个字符串较长的一个长度
	int len = max(num1.length(), num2.length());

	//格式化两个字符串，使他们具有相同长度
	num1 = formatNumber(num1, len);
	num2 = formatNumber(num2, len);

	//小于4位，直接相乘
	if (len <= SIZE)
		return to_string(atoi(num1.c_str()) * atoi(num2.c_str()));

	//将num1、num2对半分成两部分
	int len1 = len / 2;
	int len2 = len - len1;
	string A = num1.substr(0, len1);
	string B = num1.substr(len1);
	string C = num2.substr(0, len1);
	string D = num2.substr(len1);

	//乘法法则，分块处理
	int lenM = max(len1, len2);
	string AC = multiply(A, C);
	string AD = multiply(A, D);
	string BC = multiply(B, C);
	string BD = multiply(B, D);

	//处理BD，得到原位及进位
	vector<string> sBD = dealString(BD, len2);

	//处理AD+BC的和
	string ADBC = addition(AD, BC);

	//加上BD的进位
	if (sBD[1] != "0")
		ADBC = addition(ADBC, sBD[1]);

	//得到ADBC的进位
	vector<string> sADBC = dealString(ADBC, lenM);

	//AC加上进位
	AC = addition(AC, sADBC[1]);

	str = AC + sADBC[0] + sBD[0];

	int i = 0;
	while (str[i] == '0')
	{
		i++;
	}
	return str.substr(i);
}

int main()
{
	string num1 = "6";
	string num2 = "82503";
	string res = multiply(num1, num2);
	cout << res << endl;

	system("pause");
	return 0;
}