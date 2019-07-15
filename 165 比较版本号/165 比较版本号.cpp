/*
�Ƚ������汾�� version1?�� version2��
���?version1?>?version2?����?1�����?version1?<?version2 ���� -1�� ����֮�ⷵ�� 0��

����Լ���汾�ַ����ǿգ�����ֻ�������ֺ�?. �ַ���

?. �ַ�������С���㣬�������ڷָ��������С�

 ���磬2.5 ���ǡ������롱��Ҳ���ǡ���һ�뵽���������ǵڶ����еĵ����С�汾��

 ����Լ���汾�ŵ�ÿһ����Ĭ���޶����Ϊ 0�����磬�汾�� 3.4 �ĵ�һ������汾���͵ڶ�����С�汾���޶��ŷֱ�Ϊ 3 �� 4����������͵��ļ��޶��ž�Ϊ 0��
 ?

  ʾ��?1:

  ����: version1 = "0.1", version2 = "1.1"
  ���: -1
  ʾ�� 2:

  ����: version1 = "1.0.1", version2 = "1"
  ���: 1
  ʾ�� 3:

  ����: version1 = "7.5.2.4", version2 = "7.5.3"
  ���: -1
  ʾ��?4��

  ���룺version1 = "1.01", version2 = "1.001"
  �����0
  ���ͣ�����ǰ���㣬��01�� �� ��001�� ��ʾ��ͬ������ ��1����
  ʾ�� 5��

  ���룺version1 = "1.0", version2 = "1.0.0"
  �����0
  ���ͣ�version1 û�е������޶��ţ�����ζ�����ĵ������޶���Ĭ��Ϊ ��0����
  ?

   ��ʾ��

   �汾�ַ������Ե�?��.��?�ָ��������ַ�����ɡ���������ַ���������ǰ���㡣
   �汾�ַ������Ե㿪ʼ��������������в��������������ĵ㡣
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void split(string s, vector<string>& v)
{
	int len = s.length();
	int i = 0;
	int count = 0;
	int j = 0;
	while (j < len)
	{
		if (s[j] == '.')
		{
			v.push_back(s.substr(i, count));
			i = j + 1;
			count = 0;
		}
		else
			count++;
		j++;
	}
	v.push_back(s.substr(i));
}

int compare(string s1, string s2)
{
	if (atoi(s1.c_str()) > atoi(s2.c_str()))
		return 1;
	else if (atoi(s1.c_str()) < atoi(s2.c_str()))
		return -1;
	else
		return 0;
}

int compareVersion(string version1, string version2)
{
	vector<string> v1;
	vector<string> v2;
	split(version1, v1);
	split(version2, v2);
	int maxLen = v1.size() > v2.size() ? v1.size() : v2.size();
	while (v1.size() < maxLen)
	{
		v1.push_back("0");
	}
	while (v2.size() < maxLen)
	{
		v2.push_back("0");
	}
	int i = 0;
	while (i < maxLen)
	{
		if (compare(v1[i], v2[i]) == 1)
			return 1;
		else if (compare(v1[i], v2[i]) == -1)
			return -1;
		else
			i++;
	}
	return 0;
}

int main()
{
	string version1 = "1.0";
	string version2 = "1.0.0";
	int res = compareVersion(version1, version2);
	cout << res << endl;

	system("pause");
	return 0;
}