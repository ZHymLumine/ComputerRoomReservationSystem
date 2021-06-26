#include"ComputerRoom.h"
#include<fstream>
#include"globalFile.h"
ComputerRoom::ComputerRoom()
{

}

void ComputerRoom::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
	
}


//显示菜单
void ComputerRoom::showMenu()
{
	cout << "=====================  欢迎来到机房预约系统  ====================" << endl;
	cout << "请输入您的身份: " << endl;
	cout << "\t\t -----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             1.学生代表                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             2.老师                     |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             3.管理员                   |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             0.退出                     |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t -----------------------------------------\n";
}
//获取机房信息

void ComputerRoom::getComputerRoomInfo()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		//vCom.push_back(c);
	}

	ifs.close();
}
