/*
����һ�����飬���ĵ�?i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
ʾ�� 2:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
	int len = prices.size();
	int maxProfit = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (prices[j] > prices[i])
				maxProfit = maxProfit >(prices[j] - prices[i]) ? maxProfit : (prices[j] - prices[i]);
		}
	}
	return maxProfit;
}

//һ�α���
int maxProfit1(vector<int>& prices)
{
	int len = prices.size();
	int minPrice = INT_MAX;
	int maxProfit = 0;
	for (int i = 0; i < len; i++)
	{
		if (prices[i] < minPrice)
			minPrice = prices[i];
		else
			maxProfit = maxProfit >(prices[i] - minPrice) ? maxProfit : (prices[i] - minPrice);
	}
	return maxProfit;
}

int main()
{
	vector<int> prices;
	int n;
	while (cin >> n)
	{
		prices.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int res = maxProfit1(prices);
	cout << res << endl;

	system("pause");
	return 0;
}