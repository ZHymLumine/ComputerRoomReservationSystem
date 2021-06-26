#pragma once
#include"Identity.h"
#include<iostream>
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"
using namespace std;

class Admin : public Identity
{
public:
	//Ĭ�Ϲ���
	Admin();

	//�вι���
	Admin(string name, string pwd);

	//��ʾ����Ա�����Ľ���
	virtual void openMenu();

	//����˺�
	void addAccount();

	//�鿴�˺�
	void showAccount();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearOrder();

	//��ʼ������
	void initVector();

	//����ظ�
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;
};