#include"ComputerRoom.h"
#include<fstream>
#include"globalFile.h"
ComputerRoom::ComputerRoom()
{

}

void ComputerRoom::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
	
}


//��ʾ�˵�
void ComputerRoom::showMenu()
{
	cout << "=====================  ��ӭ��������ԤԼϵͳ  ====================" << endl;
	cout << "�������������: " << endl;
	cout << "\t\t -----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             1.ѧ������                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             2.��ʦ                     |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             3.����Ա                   |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             0.�˳�                     |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t -----------------------------------------\n";
}
//��ȡ������Ϣ

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
