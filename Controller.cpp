# include"Controller.h"
vector<StuInfo>stuinfos;

void Controller::ShowCopy()//��ʾ��Ȩ
{
	cout << "\n\n\t*******************��ӭʹѧ��ϵͳ******************";
	cout << "\n\n\t******************WolfOnTheWay����******************";

}


bool Controller::Login()//�û���¼
{
	system("cls");
	int index = 0;
	int count = 0;
	char account[20];
	char pw[20];
	char ch;
	ShowCopy();
	do 
	{
		index = 0;
		count++;
		cout << "\n\n\t�����������˺ţ�";
		cin.getline(account,20, '\n');
		cin.clear();
		cout << "\n\n\t�������������룺";

		//obtain password
	
		while ((ch =getchar()) != '\n')//13Ϊ�س��ļ�ֵ
		{	
			if (ch == 8)//8Ϊ�����ļ�ֵ
			{
				if (index <= 0)
				{
					index = 0;
				}
				else 
				{
					cout << "\b\b";
					--index;
				}
			}
			else
			{
				pw[index++] = ch;
				cout << '*';
			}
		
		}
		pw[index] = '\0';


		//�ж��û�������˺ź������Ƿ���ȷ
		if (strcmp(account,"yc")==0 && (strcmp(pw, "123") == 0))
		{
			initData();//���ݳ�ʼ����

			return true;
		}
		else
		{
			if (count == 3)
			{
				cout << "\n\n�Բ������޷���Ȩ�ޣ�ϵͳ���Զ��˳�";
				exit(0);

			}
			else
			{
				cout << "\n\n�˺Ż����������ȷ�Ϻ���������<������" << (3 - count) << "��������ᣬ�س������>!!!" << endl;
			}
		}


	} while (count > 0);
	return false;

}	


void Controller::menu()//���˵�
{
	int option = 0, count = 0;
	
	while (count<1000)
	{
		system("cls");
		count = 0;
		ShowCopy();
		cout << "\n\n\t*******************���˵�******************";
		cout << "\n\n\t******************1.���ѧ����Ϣ******************";
		cout << "\n\n\t******************2.��ѯѧ����Ϣ******************";
		cout << "\n\n\t******************3.���ѧ����Ϣ******************";
		cout << "\n\n\t******************4.�޸�ѧ����Ϣ******************";
		cout << "\n\n\t******************5.ɾ��ѧ����Ϣ******************";
		cout << "\n\n\t******************6.�Ƴ�ϵͳ******************";
		do
		{
			if (count != 0)
			{
				cout << "\n\n�Բ���û�и�ѡ�������ѡ��(1-6)";
			}
			else
			{
				cout << "\n\n��ѡ�����ѡ�1-6����";
			}
			cin >> option;
			count++;
		} while (option <= 0 || option > 6);
		switch (option)
		{
		case 1:ViewInfo();
			break;
		case 2:SearchStuinfo();
			break;
		case 3:addStuinfo();
			break;
		case 4:UpdateStuinfo();
			break;
		case 5: DeleteStuinfo();
			break;
		case 6:exit(0);
			break;
		}
	}

}


void Controller::initData()//��ʼ������
{
	
	FILE *file = NULL;
	fopen_s(&file, FileName, "rb");
	assert(file != NULL);
	StuInfo stu;
	fread(&stu, 1, sizeof(StuInfo), file);
	if (!fread(&stu, 1, sizeof(StuInfo), file))
	{
		fclose(file);
		return;
	}
	stuinfos.push_back(stu);//������������Ϣѹ������֮�С�

	fclose(file);

}



void Controller::addStuinfo()//���ѧ����Ϣ
{
	system("cls");
	char sno[20] ="";//ѧ��
	char sname[20]="";//����
	char cname[20]="";//�༶
	char sex[4]="";//�Ա�
	int age = 0;
	char tel[15]="";//�绰

	cout << "\n\n\t******************���ѧ����Ϣ******************";
	cout << "\n\n\t***************����������ѧ����Ϣ******************\n";
	cout << "������ѧ��ѧ�ţ�";
	cin >> sno;
	cout << endl;
	cout << "������ѧ��������";
	cin >> sname;
	cout << endl;
	cout << "������ѧ���༶��";
	cin >> cname;
	cout << endl;
	cout << "������ѧ���Ա�";
	cin >> sex;
	cout << endl;
	cout << "������ѧ�����䣺";
	cin >> age;
	cout << endl;
	cout << "������ѧ���绰��";
	cin >> tel;
	cout << endl;
	StuInfo stu(sno, sname, cname, sex, age, tel);
	printf("%s", stu.getSno());
	cout << "��Ҫ��ӵ�ѧ����Ϣ����,��ȷ��\n";
	showStuinfo(stu);
	int result = MessageBox(NULL,"�Ƿ�ȷ����Ӹ�ѧ����Ϣ","ѧ����Ϣ���",MB_OKCANCEL|MB_ICONEXCLAMATION);
	if (result = IDOK)
	{
		if (Save(stu))
		{
			stuinfos.push_back(stu);
			
			cout << "��ӳɹ�"<<endl;
		}
		else
		{
			cout << "���ʧ��"<<endl;
		}
	}
	cout<<"���س�����"<<endl;
}


void Controller::showStuinfo(StuInfo stu)//��ʾ����ѧ����Ϣ
{
	cout.flags(ios::internal); //���˶���
	cout << setw(30) << "\n\tѧ��" << "\t ����" << "\t   �༶" << "\t       �Ա�" << "\t����" << "\t    �绰" << endl;
	stu.Show();

}


void Controller::SearchStuinfo()//��ʾ���ѧ����Ϣ
{
	system("cls");
	ShowCopy();
	cout << "\n\n\t***************��ѯѧ����Ϣ******************\n";
	if (stuinfos.size() == 0)
	{
		cout << "����ѧ����Ϣ" << endl;
	}
	else
	{
		char sno[20];
		cout << "\n\n\t��������Ҫ��ѯ��ѧ�ţ�";
		cin >> sno;
		cout << setw(30) << "\n\tѧ��" << "\t ����" << "\t   �༶" << "\t       �Ա�" << "\t����" << "\t    �绰" << endl;


		int count = 0;
		int length = strlen(sno);
		int temp = 0, j = 0;
		char arr[20];
		for (int i = 0, len = stuinfos.size(); i < len; ++i) 
		{
			strcpy_s(arr, stuinfos[i].getSno());
			temp = strlen(arr);
			length = length > temp ? temp : length;//��Խ�紦��
			for (j = 0; j < length; ++j)
			{
				if (arr[j] != (stuinfos[i].getSno())[j])
				{
					break;
				}
			}
			if (j >= length)
			{
				count++;
				stuinfos[i].Show();

			}
		}
		if (count > 0)
		{
			cout << "\n\n\t**********����" << count << "����������*********"<<endl;
		}
		else
		{
			cout << "\nû��Ҫ���ҵ�ѧ����Ϣ" << endl;
		}
		system("pause");
		
	}
}

bool Controller::Save(StuInfo stu)//���浽�ļ�
{
	fstream out(FileName, ios::out | ios::app | ios::binary);
	if (out.is_open())
	{
		out.write((char*)&stu, sizeof(StuInfo));
		out.close();
		return true;
	}

	return true;
}



void Controller::ViewInfo()//���ѧ����Ϣ
{
	system("cls");
	
	
	ShowCopy();
	cout << "\n\n\t******************���ѧ����Ϣ******************";
	cout <<setw(20)<< "\n\tѧ��" << "\t ����" << "\t   �༶" << "\t      �Ա�" << "\t����" << "\t    �绰" << endl;
	for (int i = 0; i < stuinfos.size(); ++i)
	{
		stuinfos[i].Show();
	}
	system("pause");

}


void Controller::UpdateStuinfo()//�޸�ѧ����Ϣ
{
	system("cls");
	ShowCopy();
	cout << "\n\n\t***************�޸�ѧ����Ϣ******************\n";
	if (stuinfos.empty())
	{
		cout << "����ѧ����Ϣ" << endl;
	}
	else
	{
		char sno[20];
		cout << "\n\n\t��������Ҫ�޸ĵ�ѧ����ѧ�ţ�";
		cin >> sno;
		int i, len = stuinfos.size();
		for (i = 0; i < len; ++i)
		{
			if (strcmp(sno, stuinfos[i].getSno()) == 0)
			{
				cout << "��Ҫ�޸ĵ�ѧ����Ϣ���£�" << endl;
				cout << setw(30) << "\n\tѧ��" << "\t ����" << "\t   �༶" << "\t       �Ա�" << "\t����" << "\t    �绰" << endl;
				stuinfos[i].Show();
				break;

			}
		}
		if (i >= len) 
		{
			cout << "�Բ�����û����Ҫ�޸ĵ�ѧ����Ϣ��" << endl;
		}
		else
		{
			char sname[20] = "";//����
			char cname[20] = "";//�༶
			char sex[4] = "";//�Ա�
			int age = 0;
			char tel[15] = "";//�绰


			cout << "������ѧ��������";
			cin >> sname;
			cout << endl;
			cout << "������ѧ���༶��";
			cin >> cname;
			cout << endl;
			cout << "������ѧ���Ա�";
			cin >> sex;
			cout << endl;
			cout << "������ѧ�����䣺";
			cin >> age;
			cout << endl;
			cout << "������ѧ���绰��";
			cin >> tel;
			cout << endl;
			int result = MessageBox(NULL, "ȷ���޸Ĵ�ѧ������Ϣ��", "ѧ����Ϣ�޸�", MB_OKCANCEL | MB_ICONEXCLAMATION);
			if (result == IDOK)
			{
				stuinfos[i].setCname(sname);
				stuinfos[i].setCname(cname);
				stuinfos[i].setSex(sex);
				stuinfos[i].setAge(age);
				stuinfos[i].setTel(tel);
				if(reWrite())
				{
					cout << "��Ϣ�޸ĳɹ�" << endl;
				}
				else
				{
					cout << "��Ϣ�޸�ʧ��" << endl;
				}

			}

		}

	}
	system("pause");

}



void Controller::DeleteStuinfo()//ɾ��ѧ����Ϣ
{

	system("cls");
	ShowCopy();
	cout << "\n\n\t***************ɾ��ѧ����Ϣ******************\n";
	if (stuinfos.empty())
	{
		cout << "����ѧ����Ϣ" << endl;
	}
	else
	{
		char sno[20];
		cout << "\n\n\t��������Ҫɾ��ѧ����ѧ�ţ�" << endl;
		cin >> sno;
		int i = 0, len = stuinfos.size();
		for ( ; i < len; ++i)
		{
			if (strcmp(sno, stuinfos[i].getSno()) == 0)
			{
				cout << setw(30) << "\n\tѧ��" << "\t ����" << "\t   �༶" << "\t       �Ա�" << "\t����" << "\t    �绰" << endl;
				stuinfos[i].Show();
				break;
			}
		}
		if (i >= len)
		{

			cout << "û����Ҫɾ����ѧ����Ϣ" << endl;
		}
		else
		{
			stuinfos.erase(stuinfos.begin() + i);
			int result = MessageBox(NULL, "ȷ��ɾ����ѧ������Ϣ��", "ѧ����Ϣɾ��", MB_OKCANCEL | MB_ICONEXCLAMATION);
			if (result == IDOK)
			{
				if (reWrite())
				{
					cout << "ѧ����Ϣɾ���ɹ�" << endl;
				}
				else
				{
					cout << "ѧ����Ϣɾ��ʧ��" << endl;
				}

			}

		}
		
	}
	system("pause");
}


bool Controller::reWrite()//����д���ļ�
{

	int len = stuinfos.size();
	if (len <= 0)
	{
		fstream out(FileName, ios::out | ios::trunc);
		out.close();
	}
	else
	{

		fstream out(FileName, ios::out | ios::binary);
		if (out.is_open())
		{
			for (int i = 0; i < stuinfos.size(); ++i)
			{
				out.write((char*)&stuinfos[i], sizeof(StuInfo));
			}
			out.close();
			return true;
		}
		else
		{
			return false;
		}

	}
	return false;

}