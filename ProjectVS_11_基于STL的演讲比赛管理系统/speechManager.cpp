#include"speechManager.h"


SpeechManager::SpeechManager()
{
	this->initSpeech();//��ʼ������

	this->creatSpeaker();//����ѡ��

	this->loadRecord();//��ȡ�����¼
}

void SpeechManager::show_menu()
{
	cout << "********************************************" << endl; 
	cout << "************* ��ӭ�μ��ݽ����� ************" << endl; 
	cout << "*************  1.��ʼ�ݽ����� *************" << endl; 
	cout << "*************  2.�鿴�����¼ *************" << endl; 
	cout << "*************  3.��ձ�����¼ *************" << endl; 
	cout << "*************  0.�˳��������� *************" << endl; 
	cout << "********************************************" << endl; 
	cout << endl;
	
}
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´ε�½��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_index = 1;
	//��ʼ����¼����
	this->m_record.clear();
	
}
void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_score[i] = 0;
		}
		//12��ѡ�ֱ��
		this->v1.push_back(i + 1001);

		//ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 1001, sp));

	}

}
void SpeechManager::startSpeech()
{
	//��һ�ֱ��� 
	
	//1����ǩ 
	this->speechDraw();
	//2������ 
	this->speechContest();
	//3����ʾ������� 
	this->showScore();

	//�ڶ��ֱ��� 
	this->m_index++;
	//1����ǩ 
	this->speechDraw();
	//2������ 
	this->speechContest();
	//3����ʾ���ս�� 
	this->showScore();
	//4���������
	this->saveRecord();

	//���ñ���
	//��ʼ������
	this->initSpeech();
	//����ѡ��
	this->creatSpeaker();
	//��ȡ�����¼
	this->loadRecord();

	cout << "���������ϣ�" << endl;

	system("pause");
	system("cls");
}
void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_index << ">>����ѡ�ֳ�ǩ��˳�����£�" << endl;
	if (this->m_index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	system("pause");
	cout << endl;
}
void SpeechManager::speechContest()
{
	cout << "---------��" << this->m_index << "�ֱ�����ʽ��ʼ��----------" << endl;

	multimap<double, int, greater<int>> groupSorce; //��ʱ����������key���� value ѡ�ֱ��

	int num = 0;
	vector<int> v_Str;
	if (this->m_index == 1)
	{
		v_Str = v1;
	}
	else
	{
		v_Str = v2;
	}

	for (vector<int>::iterator it = v_Str.begin();it != v_Str.end();it++)
	{
		num++;

		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double sorce = (rand() % 401 + 600) / 10.f;
			d.push_back(sorce);
		}
		sort(d.begin(), d.end(), greater<double>());//����
		d.pop_back();//ȥ����ͷ�
		d.pop_front();//ȥ����߷�

		double sum = accumulate(d.begin(), d.end(),0.0f);
		double avg = sum / (double)d.size();

		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;

		//6����һ�飬����ʱ��������
		groupSorce.insert(make_pair(avg, *it));

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupSorce.begin(); it != groupSorce.end(); it++)
			{
				cout << "��ţ�" << it->second << "  ������" << this->m_Speaker[it->second].m_name
					<< "  �ɼ���" << this->m_Speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			cout << endl;
			int count = 0;
			for (multimap<double, int, greater<int>>::iterator it = groupSorce.begin(); it != groupSorce.end() && count < 3; it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v3.push_back((*it).second);
				}
			}
			groupSorce.clear();
			cout << endl;
		}
	}
	cout << "-----------��<<" << this->m_index << ">>�ֱ�������-------------" << endl;
	system("pause");
}
void SpeechManager::showScore()
{
	cout << "��<<" << this->m_index << ">>�ֵı���������������:" << endl;
	vector<int> v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << "  ������" << m_Speaker[*it].m_name << "  �÷֣�"
			<< m_Speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_menu();
}
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽ���ļ� -- д�ļ�
	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();

	cout << "��¼�ѱ��棡" << endl;

	//���¼�¼Ϊ�ǿ�
	this->fileIsEmpty = false;
	
}
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in);//���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;

	ifs.putback(ch);//��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v;
		int start = 0;
		int pos = -1;

		while (true)
		{
			pos = data.find(",", start);//��0��ʼ���� ','
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);//�ҵ���,���зָ� ����1 ��ʼλ�ã��� ��2 ��ȡ����
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	
}
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "��" << i + 1 << "��" <<
				"  �ھ���ţ�" << m_record[i][0] << "  ������" << m_record[i][1] <<
				"  �Ǿ���ţ�" << m_record[i][2] << "  ������" << m_record[i][3] <<
				"  ������ţ�" << m_record[i][4] << "  ������" << m_record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
void SpeechManager::clearRecord()
{
	cout << "��ȷ��Ҫ�����" << endl;
	cout << "1.ȷ��       2.ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();//��ʼ������

		this->creatSpeaker();//����ѡ��

		this->loadRecord();//��ȡ�����¼

		cout << "��ճɹ���" << endl; 
	}
	system("pause");
	system("cls");
}
SpeechManager::~SpeechManager()
{

}