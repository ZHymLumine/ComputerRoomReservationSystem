#pragma once
#include<iostream>
#include<vector>
#include"orderFile.h"
using namespace std;

class ComputerRoom
{
public:
	ComputerRoom();
	
	// �˳�ϵͳ
	void exitSystem();  

	//��ʾ�˵�
	void showMenu();

	//��ȡ������Ϣ
	void getComputerRoomInfo();

	int m_ComId; //����id��

	int m_MaxNum; //�����������

	vector<OrderFile> orf;
};