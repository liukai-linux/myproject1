#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>

//����ݽ�������
class SpeechManager
{
public:
	SpeechManager();

	void show_menu();//�˵�����

	void exitSystem();//�˳�����

	void initSpeech();//��ʼ������

	void creatSpeaker();//����ѡ��

	void startSpeech();//��ʼ����

	void speechDraw();//��ǩ

	void speechContest();//����

	void showScore();//��ʾ�������

	void saveRecord();//�����¼

	void loadRecord();//��ȡ��¼

	bool fileIsEmpty;//�ļ�Ϊ�յı�־

	void showRecord();//��ʾ����÷�

	void clearRecord();//��ռ�¼

	~SpeechManager();

	vector<int> v1;//����ѡ�� ���� 12��

	vector<int> v2;//��һ�ֽ������� 6��

	vector<int> v3;//ʤ��ǰ�������� 3��

	map<int, Speaker> m_Speaker;//��ű�� �Լ���Ӧ�� ����ѡ�� ����

	int m_index;//��ű�������

	map<int, vector<string>> m_record;//�����¼

};