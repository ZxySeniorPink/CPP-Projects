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

	//��¼��������
	int m_Round;

	//��¼������¼�Ƿ�Ϊ��
	bool RecordIsEmpty;

	//��¼�������������
	map<int, vector<string>> m_Record;

	//��һ�ֵı���ѡ��������12��
	vector<int> v_Round1;

	//�ڶ��ֵı���ѡ��������6��
	vector<int> v_Round2;

	//�񽱵�ǰ����������3��
	vector<int> v_Victory;

	//��ű���Լ���Ӧ�ľ���ѡ�ֵ�����
	map<int, Speaker> m_Speaker;

	//���캯��
	SpeechContestManager();

	//��ʾ���ܲ˵�
	void ShowMenu();

	//��ʼ����Ա����
	void InitSpeech();

	//�����ݽ�ѡ��
	void CreateSpeaker();

	//��ʼ�ݽ�����
	void StartSpeech();

	//��ǩ
	void SpeechDraw();

	//����
	void SpeechContest();

	//��ʾ�÷�
	void SpeechResult();

	//�����¼
	void SaveRecord();

	//��ȡ��¼
	void LoadRecord();

	//�鿴��¼
	void ShowRecord();

	//��ռ�¼
	void ClearRecord();

	//�˳�����
	void ExitContest();

	//��������
	~SpeechContestManager();

};