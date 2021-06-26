#pragma once
#include<iostream>
#include<vector>
#include"orderFile.h"
using namespace std;

class ComputerRoom
{
public:
	ComputerRoom();
	
	// 退出系统
	void exitSystem();  

	//显示菜单
	void showMenu();

	//获取机房信息
	void getComputerRoomInfo();

	int m_ComId; //机房id号

	int m_MaxNum; //机房最大容量

	vector<OrderFile> orf;
};