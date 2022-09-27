#pragma once
#include "Speaker.h"
#include <fstream>
#include <map>
#include <deque>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>


class SpeechContestManager
{
public:

	//记录比赛轮数
	int m_Round;

	//记录比赛记录是否为空
	bool RecordIsEmpty;

	//记录往届比赛的容器
	map<int, vector<string>> m_Record;

	//第一轮的比赛选手容器：12人
	vector<int> v_Round1;

	//第二轮的比赛选手容器：6人
	vector<int> v_Round2;

	//获奖的前三名容器：3人
	vector<int> v_Victory;

	//存放编号以及对应的具体选手的容器
	map<int, Speaker> m_Speaker;

	//构造函数
	SpeechContestManager();

	//显示功能菜单
	void ShowMenu();

	//初始化成员属性
	void InitSpeech();

	//创建演讲选手
	void CreateSpeaker();

	//开始演讲比赛
	void StartSpeech();

	//抽签
	void SpeechDraw();

	//比赛
	void SpeechContest();

	//显示得分
	void SpeechResult();

	//保存记录
	void SaveRecord();

	//读取记录
	void LoadRecord();

	//查看记录
	void ShowRecord();

	//清空记录
	void ClearRecord();

	//退出比赛
	void ExitContest();

	//析构函数
	~SpeechContestManager();

};