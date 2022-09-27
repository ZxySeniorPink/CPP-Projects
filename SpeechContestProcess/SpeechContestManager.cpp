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
	//����ȫ���ÿ�
	this->v_Round1.clear();
	this->v_Round2.clear();
	this->v_Victory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	//��ʼ����������
	this->m_Round = 1;
	//�����¼�Ƿ�Ϊ��
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
		//����ѡ�ֱ�� ���ҷ��뵽v1������
		this->v_Round1.push_back(i + 10001);

		this->m_Speaker.insert(make_pair(i + 10001, speaker));
	}
}

void SpeechContestManager::StartSpeech()
{
	//��һ�ֱ���

	//1����ǩ
	this->SpeechDraw();
	//2������
	this->SpeechContest();
	//3����ʾ�������
	this->SpeechResult();

	//�ڶ��ֱ���
	this->m_Round++;

	//1����ǩ
	this->SpeechDraw();
	//����
	this->SpeechContest();
	//��ʾ���ս��
	this->SpeechResult();

	//�������
	this->SaveRecord();

	//���ñ�����Ϣ
	this->InitSpeech();

	this->CreateSpeaker();

	this->LoadRecord();

	cout << "\nSpeech Contest is over��" << endl;
	system("pause");
	system("cls");
}

void SpeechContestManager::SpeechDraw()
{
	cout << "\nRound" << this->m_Round << "��Speakers is drawing lots" << endl;
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

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>> group_score;
	//��¼��Ա���� 6��һ��
	int num = 0;
	//����ѡ������
	vector<int> speakers;

	if (this->m_Round == 1)
	{
		speakers = this->v_Round1;
	}
	else
	{
		speakers = this->v_Round2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = speakers.begin(); it != speakers.end(); it++)
	{
		num++;
		//��ί���
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

		//��ӡƽ����
		cout << "SpeakerNo: " << *it << "  Name: " << this->m_Speaker[*it].m_Name << "  Average score: " << avg << endl;

		//��ƽ���ַ��뵽map������
		this->m_Speaker[*it].m_Score[this->m_Round - 1] = avg;

		//��������ݷ��뵽��ʱ��С��������
		//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		group_score.insert(make_pair(avg, *it));

		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "\nGroup" << num / 6 << "'s Ranking" << endl;
			for (multimap<double, int, greater<double>>::iterator it = group_score.begin(); it != group_score.end(); it++)
			{
				cout << "Speaker.No: " << it->second << "  Name: " << this->m_Speaker[it->second].m_Name << "  Score: " << this->m_Speaker[it->second].m_Score[this->m_Round - 1] << endl;
			}

			//ȡ��ǰ����
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
			//С���������
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

	//����ļ�������
	if (!ifs.is_open())
	{
		/*	cout << "No exist any record" << endl;*/
		this->RecordIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		/*	cout << "Record is empty" << endl;*/
		this->RecordIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ�� �Żظոն�ȡ�����ĵ�һ���ַ�
	this->RecordIsEmpty = false;
	ifs.putback(ch);

	string data;
	//��ʼ��¼
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
				//�Ҳ�����break����
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
	cout << "1��Yes" << endl;
	cout << "2��No" << endl;

	int choice = 0;
	cin >> choice;

	//ȷ�����
	if (choice == 1)
	{
		ofstream ofs("speech_contest_record.csv", ios::trunc);
		ofs.close();
		//��ʼ������������
		this->InitSpeech();

		//����ѡ��
		this->CreateSpeaker();

		//���������¼
		this->LoadRecord();

		cout << "Clear successfully!" << endl;
	}

	system("pause");
	system("cls");
}
