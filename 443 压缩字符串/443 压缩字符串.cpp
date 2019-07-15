/*
����һ���ַ���ʹ��ԭ���㷨����ѹ����

ѹ����ĳ��ȱ���ʼ��С�ڻ����ԭ���鳤�ȡ�

�����ÿ��Ԫ��Ӧ���ǳ���Ϊ1?���ַ������� int �������ͣ���

�����ԭ���޸���������󣬷���������³��ȡ�

?

 ���ף�
 ���ܷ��ʹ��O(1) �ռ������⣿

  ʾ�� 1��

  ���룺
  ["a","a","b","b","c","c","c"]

  �����
  ����6�����������ǰ6���ַ�Ӧ���ǣ�["a","2","b","2","c","3"]

  ˵����
  "aa"��"a2"�����"bb"��"b2"�����"ccc"��"c3"�����
  ʾ�� 2��

  ���룺
  ["a"]

  �����
  ����1�����������ǰ1���ַ�Ӧ���ǣ�["a"]

  ˵����
  û���κ��ַ����������
  ʾ�� 3��

  ���룺
  ["a","b","b","b","b","b","b","b","b","b","b","b","b"]

  �����
  ����4�����������ǰ4���ַ�Ӧ���ǣ�["a","b","1","2"]��

  ˵����
  �����ַ�"a"���ظ������Բ��ᱻѹ����"bbbbbbbbbbbb"����b12�������
  ע��ÿ�������������ж������Լ���λ�á�
  ע�⣺

  �����ַ�����һ��ASCIIֵ��[35, 126]�����ڡ�
  1 <= len(chars) <= 1000��
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars)
{
	int len = chars.size();
	if (len == 0 || len == 1)
		return len;
	vector<char> c;
	vector<string> num;
	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		count = 1;
		int j = i + 1;
		while (j < len && chars[j] == chars[i])
		{
			count++;
			j++;
		}
		num.push_back(to_string(count));
		c.push_back(chars[i]);
		i = j - 1;
	}
	if (chars[len - 2] != chars[len - 1])
	{
		c.push_back(chars[len - 1]);
		num.push_back(to_string(1));
	}
	chars.clear();
	int numLen = num.size();
	int res = 0;
	for (int i = 0; i < numLen; i++)
	{
		chars.push_back(c[i]);
		res++;
		if (num[i] != "1")
		{
			for (int j = 0; j < num[i].size(); j++)
			{
				chars.push_back(num[i][j]);
				res++;
			}
		}
	}
	return res;
}

int compress1(vector<char>& chars)
{
	if (chars.size() <= 1)
		return chars.size();
	int index = 0;
	for (int i = 0; i < chars.size();)
	{
		chars[index++] = chars[i++];
		int count = 1;
		while (i < chars.size() && chars[i] == chars[i - 1])
		{
			count++;
			i++;
		}
		if (count != 1)
		{
			string s = to_string(count);
			for (int j = 0; j < s.length(); j++)
				chars[index++] = s[j];
		}
	}
	chars.erase(chars.begin() + index, chars.end());
	return chars.size();
}

int main()
{
	vector<char> chars = { 'a' };
	int res = compress1(chars);
	cout << res << endl;

	system("pause");
	return 0;
}