/*
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z ��
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return "";
	}
	string res = strs[0];
	for (int i = 1; i < strs.size(); i++)
	{
		for (int j = 0; j < res.length(); j++)
		{
			if (res[j] == strs[i][j])
			{
				continue;
			}
			else
			{
				res.erase(j);
				break;
			}
		}
	}
	return res;
}

int main()
{
	vector<string> v{ "aa","a" };
	string ret = longestCommonPrefix(v);
	cout << ret << endl;

	system("pause");
	return 0;
}