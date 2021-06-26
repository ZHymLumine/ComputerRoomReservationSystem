#pragma once
#include"Identity.h"
#include<iostream>
using namespace std;

class Teacher : public Identity
{

public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void openMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();
	
	//职工号
	int m_EmpId;
};