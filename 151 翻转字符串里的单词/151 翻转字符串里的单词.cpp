/*
����һ���ַ����������ת�ַ����е�ÿ�����ʡ�

?

ʾ�� 1��

����: "the sky is blue"
���:?"blue is sky the"
ʾ�� 2��

����: " ?hello world! ?"
���:?"world! hello"
����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
ʾ�� 3��

����: "a good ? example"
���:?"example good a"
����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
 ?

˵����

�޿ո��ַ�����һ�����ʡ�
�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
  ?

���ף�

��ѡ�� C ���Ե��û�����ʹ��?O(1) ����ռ临�Ӷȵ�ԭ�ؽⷨ��
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseWords(string s)
{
	s.erase(0, s.find_first_not_of(' '));
	s.erase(s.find_last_not_of(' ') + 1);
	string res;
	int i = 0;
	string temp = "";
	stack<string> sta;
	while (i <= s.length())
	{
		if (s[i] == ' ' || s[i] == '\0')
		{
			if (temp.length())
			{
				sta.push(temp);
				temp = "";
			}
		}
		else
			temp += s[i];
		i++;
	}
	int size = sta.size();
	for (int i = 0; i < size; i++)
	{
		if (sta.size() == 1)
			res += sta.top();
		else
		{
			res += sta.top() + ' ';
			sta.pop();
		}
	}
	return res;
}

int main()
{
	string s = "  hello world!  ";
	string res = reverseWords(s);
	cout << res << endl;

	system("pause");
	return 0;
}