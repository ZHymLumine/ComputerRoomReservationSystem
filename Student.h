#pragma once
#include"Identity.h"
#include<iostream>
#include"ComputerRoom.h"
#include<vector>
using namespace std;

class Student : public Identity
{	
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	
	//�˵�����
	virtual void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;  //ѧ��

	//��������
	vector<ComputerRoom> vCom;
};