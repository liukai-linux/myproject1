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

//设计演讲管理类
class SpeechManager
{
public:
	SpeechManager();

	void show_menu();//菜单功能

	void exitSystem();//退出功能

	void initSpeech();//初始化属性

	void creatSpeaker();//创建选手

	void startSpeech();//开始比赛

	void speechDraw();//抽签

	void speechContest();//比赛

	void showScore();//显示比赛结果

	void saveRecord();//保存记录

	void loadRecord();//读取记录

	bool fileIsEmpty;//文件为空的标志

	void showRecord();//显示往届得分

	void clearRecord();//清空记录

	~SpeechManager();

	vector<int> v1;//比赛选手 容器 12人

	vector<int> v2;//第一轮晋级容器 6人

	vector<int> v3;//胜利前三名容器 3人

	map<int, Speaker> m_Speaker;//存放编号 以及对应的 具体选手 容器

	int m_index;//存放比赛轮数

	map<int, vector<string>> m_record;//往届记录

};