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

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();
	
	//ְ����
	int m_EmpId;
};