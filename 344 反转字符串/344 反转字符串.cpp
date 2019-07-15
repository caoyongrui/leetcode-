/*
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���

?

 ʾ�� 1��

 ���룺["h","e","l","l","o"]
 �����["o","l","l","e","h"]
 ʾ�� 2��

 ���룺["H","a","n","n","a","h"]
 �����["h","a","n","n","a","H"]
*/

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s)
{
	int i = 0;
	int j = s.size() - 1;
	char temp;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

int main()
{
	vector<char> s = { 'H','a','n','n','a','h' };
	reverseString(s);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}