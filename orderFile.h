#pragma once
#include<iostream>
#include<map>
using namespace std;

class OrderFile
{
public:
	OrderFile();
	
	//����ԤԼ
	void updateOrder();
	
	//��¼ԤԼ����
	int m_Size;
	
	//��¼����ԤԼ��Ϣ
	map<int, map<string, string>> m_OrderData;
};