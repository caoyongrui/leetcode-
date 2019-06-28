/*
�����������ַ�����ʽ��ʾ�ķǸ�����?num1?��?num2������?num1?��?num2?�ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��

ʾ�� 1:

����: num1 = "2", num2 = "3"
���: "6"
ʾ��?2:

����: num1 = "123", num2 = "456"
���: "56088"
˵����

num1?��?num2?�ĳ���С��110��
num1 ��?num2 ֻ��������?0-9��
num1 ��?num2?�������㿪ͷ������������ 0 ����
����ʹ���κα�׼��Ĵ������ͣ����� BigInteger����ֱ�ӽ�����ת��Ϊ����������
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

static int SIZE = 4;

//��ʽ���ַ�������
string formatNumber(string s, int len)
{
	while (s.length() < len)
	{
		s = "0" + s;
	}
	return s;
}

//�������ִ����������λ
//string�����һ��Ϊԭλ���ڶ���Ϊ��λ
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
	//���ص��ַ���
	string str = "";

	//�����ַ���Ҫ��ͬ
	int lenM = max(s1.length(), s2.length());
	s1 = formatNumber(s1, lenM);
	s2 = formatNumber(s2, lenM);

	//��λ�ӣ���λ�洢��flag��
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

	//����ַ���
	string str = "";

	//��������ַ����ϳ���һ������
	int len = max(num1.length(), num2.length());

	//��ʽ�������ַ�����ʹ���Ǿ�����ͬ����
	num1 = formatNumber(num1, len);
	num2 = formatNumber(num2, len);

	//С��4λ��ֱ�����
	if (len <= SIZE)
		return to_string(atoi(num1.c_str()) * atoi(num2.c_str()));

	//��num1��num2�԰�ֳ�������
	int len1 = len / 2;
	int len2 = len - len1;
	string A = num1.substr(0, len1);
	string B = num1.substr(len1);
	string C = num2.substr(0, len1);
	string D = num2.substr(len1);

	//�˷����򣬷ֿ鴦��
	int lenM = max(len1, len2);
	string AC = multiply(A, C);
	string AD = multiply(A, D);
	string BC = multiply(B, C);
	string BD = multiply(B, D);

	//����BD���õ�ԭλ����λ
	vector<string> sBD = dealString(BD, len2);

	//����AD+BC�ĺ�
	string ADBC = addition(AD, BC);

	//����BD�Ľ�λ
	if (sBD[1] != "0")
		ADBC = addition(ADBC, sBD[1]);

	//�õ�ADBC�Ľ�λ
	vector<string> sADBC = dealString(ADBC, lenM);

	//AC���Ͻ�λ
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