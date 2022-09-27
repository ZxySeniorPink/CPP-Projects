#include "SpeechContestManager.h"

SpeechContestManager::SpeechContestManager()
{
	this->InitSpeech();

	this->CreateSpeaker();

	this->LoadRecord();

}

SpeechContestManager::~SpeechContestManager()
{

}

void SpeechContestManager::ShowMenu()
{
	cout << "|-------------------------------------------------|" << endl;
	cout << "|========    WELCOME TO SPEECH CONTEST    ========|" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "|***          1: START SPEECH CONTEST!        ****|" << endl;
	cout << "|***          2: VIEW PREVIOUS RECORDS        ****|" << endl;
	cout << "|***          3: CLEAR CURRENT RECORDS        ****|" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "|                              ...PRESS 0 TO EXIT |" << endl;
	cout << "|-------------------------------------------------|" << endl;
}

void SpeechContestManager::ExitContest()
{
	system("cls");
	cout << "Look forward to your next use!" << endl;
	exit(0);
}

void SpeechContestManager::InitSpeech()
{
	//容器全部置空
	this->v_Round1.clear();
	this->v_Round2.clear();
	this->v_Victory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	//初始化比赛轮数
	this->m_Round = 1;
	//往届记录是否为空
	this->RecordIsEmpty = true;
}

void SpeechContestManager::CreateSpeaker()
{
	string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < name_seed.size(); i++)
	{
		string name = "Speaker";
		name += name_seed[i];

		Speaker speaker;
		speaker.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			speaker.m_Score[j] = 0;
		}
		//创建选手编号 并且放入到v1容器中
		this->v_Round1.push_back(i + 10001);

		this->m_Speaker.insert(make_pair(i + 10001, speaker));
	}
}

void SpeechContestManager::StartSpeech()
{
	//第一轮比赛

	//1、抽签
	this->SpeechDraw();
	//2、比赛
	this->SpeechContest();
	//3、显示紧急结果
	this->SpeechResult();

	//第二轮比赛
	this->m_Round++;

	//1、抽签
	this->SpeechDraw();
	//比赛
	this->SpeechContest();
	//显示最终结果
	this->SpeechResult();

	//保存分数
	this->SaveRecord();

	//重置比赛信息
	this->InitSpeech();

	this->CreateSpeaker();

	this->LoadRecord();

	cout << "\nSpeech Contest is over！" << endl;
	system("pause");
	system("cls");
}

void SpeechContestManager::SpeechDraw()
{
	cout << "\nRound" << this->m_Round << "：Speakers is drawing lots" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "The result of drawing lots is as follows\n" << endl;
	if (this->m_Round == 1)
	{
		int group = 0;
		random_shuffle(this->v_Round1.begin(), this->v_Round1.end());
		for (vector<int>::iterator it = v_Round1.begin(); it != v_Round1.end(); it++, group++)
		{
			if (group == 6)
				cout << endl;
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v_Round2.begin(), this->v_Round2.end());
		for (vector<int>::iterator it = v_Round2.begin(); it != v_Round2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------------------------------------------------" << endl;
	system("pause");
}

void SpeechContestManager::SpeechContest()
{
	cout << "---------------------------- Round" << this->m_Round << " start ----------------------------\n" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>> group_score;
	//记录人员个数 6人一组
	int num = 0;
	//比赛选手容器
	vector<int> speakers;

	if (this->m_Round == 1)
	{
		speakers = this->v_Round1;
	}
	else
	{
		speakers = this->v_Round2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = speakers.begin(); it != speakers.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();

		//打印平均分
		cout << "SpeakerNo: " << *it << "  Name: " << this->m_Speaker[*it].m_Name << "  Average score: " << avg << endl;

		//将平均分放入到map容器里
		this->m_Speaker[*it].m_Score[this->m_Round - 1] = avg;

		//将打分数据放入到临时的小组容器中
		//key是得分，value是具体选手编号
		group_score.insert(make_pair(avg, *it));

		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "\nGroup" << num / 6 << "'s Ranking" << endl;
			for (multimap<double, int, greater<double>>::iterator it = group_score.begin(); it != group_score.end(); it++)
			{
				cout << "Speaker.No: " << it->second << "  Name: " << this->m_Speaker[it->second].m_Name << "  Score: " << this->m_Speaker[it->second].m_Score[this->m_Round - 1] << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = group_score.begin(); it != group_score.end() && count < 3; it++, count++)
			{
				if (this->m_Round == 1)
				{
					this->v_Round2.push_back(it->second);
				}
				else
				{
					this->v_Victory.push_back(it->second);
				}
			}
			//小组容器清空
			group_score.clear();
			cout << endl;
		}
	}
	cout << "---------------------------- Round" << this->m_Round << " over! ----------------------------\n" << endl;
	system("pause");

}

void SpeechContestManager::SpeechResult()
{
	cout << "---------------------------- Round" << this->m_Round << " Promotion Result ---------------------------- " << endl;

	vector<int> v;
	if (this->m_Round == 1)
	{
		v = this->v_Round2;
	}
	else
	{
		v = this->v_Victory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "SpeakerNo: " << *it << "\tName: " << this->m_Speaker[*it].m_Name << "\tScore: " << this->m_Speaker[*it].m_Score[this->m_Round - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->ShowMenu();
}

void SpeechContestManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech_contest_record.csv", ios::out | ios::app);
	for (vector<int>::iterator it = this->v_Victory.begin(); it != this->v_Victory.end(); it++)
	{
		ofs << *it << ',' << this->m_Speaker[*it].m_Score[1] << ',';
	}
	ofs << endl;

	ofs.close();

	cout << "\nSpeech contest record has been saved!" << endl;

	this->RecordIsEmpty = false;
}

void SpeechContestManager::LoadRecord()
{
	ifstream ifs;
	ifs.open("speech_contest_record.csv", ios::in);

	//如果文件不存在
	if (!ifs.is_open())
	{
		/*	cout << "No exist any record" << endl;*/
		this->RecordIsEmpty = true;
		ifs.close();
		return;
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		/*	cout << "Record is empty" << endl;*/
		this->RecordIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空 放回刚刚读取出来的第一个字符
	this->RecordIsEmpty = false;
	ifs.putback(ch);

	string data;
	//开始记录
	int session = 0;
	while (ifs >> data)
	{
		vector<string> v;
		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//找不到就break返回
				break;
			}

			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(session, v));
		session++;
	}
	ifs.close();
}

void SpeechContestManager::ShowRecord()
{
	if (this->RecordIsEmpty)
	{
		cout << "No exist record" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "No." << i + 1 << "'s Session: "
				<< "  1stNo." << this->m_Record[i][0] << "  Score: " << this->m_Record[i][1]
				<< "\t2ndNo." << this->m_Record[i][2] << "  Score: " << this->m_Record[i][3]
				<< "\t3rdNo." << this->m_Record[i][4] << "  Score: " << this->m_Record[i][5] << endl;
		}
	}

	system("pause");
	system("cls");

}

void SpeechContestManager::ClearRecord()
{
	cout << "Are you sure you want to clear?" << endl;
	cout << "1、Yes" << endl;
	cout << "2、No" << endl;

	int choice = 0;
	cin >> choice;

	//确认清空
	if (choice == 1)
	{
		ofstream ofs("speech_contest_record.csv", ios::trunc);
		ofs.close();
		//初始化容器和属性
		this->InitSpeech();

		//创建选手
		this->CreateSpeaker();

		//加载往届记录
		this->LoadRecord();

		cout << "Clear successfully!" << endl;
	}

	system("pause");
	system("cls");
}
