#pragma once
#include<iostream>
#include<map>
using namespace std;

class OrderFile
{
public:
	OrderFile();
	
	//更新预约
	void updateOrder();
	
	//记录预约条数
	int m_Size;
	
	//记录所有预约信息
	map<int, map<string, string>> m_OrderData;
};