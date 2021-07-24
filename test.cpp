#include<iostream> 
#include<string>
#include <vector>
#include <iomanip>
#define MaxScore 100
using namespace std;

class Student {
public:
	
	friend ostream& operator<<(ostream& output, const Student& S)
	{
		output << "ѧ��:"<< setw(8) << setfill(' ') << setiosflags(ios::left)<<S.getNumber()
			   << "����:" << setw(8) << setfill(' ') << S.getName()
			   << "�ɼ�:" << setw(4) << setfill(' ') << S.getScore();
		return output;
	}
	friend istream& operator>>(istream& input, Student& S)
	{
		int number, score;
		string name;
		cout << "������ѧ������\n";
		cin >> name;
		cout << "������ѧ��ѧ��\n";
		cin >> number;
		cout << "������ѧ���ɼ�\n";
		cin >> score;
		while (cin.fail() || score < 0 || score>MaxScore) {
			cout << "error input,please reinput";
			cin.clear();
			cin.ignore(65535, '\n');
			cin >> score;
		}

		S.setNumber(number);
		S.setScore(score);
		S.setName(name);
		return input;
	}

	int getNumber()const{
		return m_stud_num;
	}
	void setNumber(int num){
		m_stud_num = num;
	}

	void setScore(int score) {
		m_score = score;
	}
	int getScore() const{
		return m_score;
	}
	void modifyScore(int score) {
		m_score = score;
	}

	void setName(string& name) {
		m_name = name;
	}
	bool isExcellent() {
		return (m_score >= 90) ? true : false;
	}
	bool isPass() {
		return (m_score >= 60) ? true : false;
	}
	string getName() const{ 
		return m_name;
	}//return the name of student

	void clear() {
		m_stud_num = -1;
		m_score = -1;
		m_name = "NULL Name";
	}
private:
	int m_stud_num;
	int m_score;
	string m_name;
};

class VecStudent {
public:
	void outputAllDetail(ostream& os = cout);
	void addStud(Student& s) {
		m_vecStudent.push_back(s);
	}
	void findStud();
	void modifyScore();

	int passNum();
	int excellentNum();

private:
	vector<Student> m_vecStudent;
};

void VecStudent::findStud() {
	cout << "������:��������ѯ(1)or��ѧ�Ų�ѯ(2)";
	int choose;
	cin >> choose;
	while (cin.fail() || (choose != 1 && choose != 2)) {
		cout << "error input,please reinput";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> choose;
	}
	if (1 == choose) {
		cout << "����������";
		string name;
		cin >> name;
		for (auto i : m_vecStudent) {
			if (name == i.getName()) {
				cout << "��ѧ����ϢΪ" << i;
				return;
			}
		}
		cout << "��ѧ��������!\n";
		cin.clear();
		cin.ignore(65535, '\n');
	}
	else if (2 == choose) {
		cout << "������ѧ��:";
		int number;
		cin >> number;
		for (auto i : m_vecStudent) {
			if (number == i.getNumber()) {
				cout << "��ѧ����ϢΪ:" << i;
				return;
			}
			
		}
		cout << "��ѧ��������!\n";
		cin.clear();
		cin.ignore(65535, '\n');
	}
}

void VecStudent::modifyScore()
{
	int finalScore = 0;

	cout << "�������ѯ��ʽ:��������ѯ(1)or��ѧ�Ų�ѯ(2)";
	int choose;
	cin >> choose;
	while (cin.fail() || (choose != 1 && choose != 2)) {
		cout << "error input,please reinput";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> choose;
	}
	if (1 == choose) {
		cout << "����������:";
		string name;
		cin >> name;
		int j = 0;
		for (auto i = m_vecStudent.begin(); i < m_vecStudent.end();i++,j++) {
			if (name == i->getName()) {
				cout << "�������޸ĺ�ĳɼ�:";
				cin >> finalScore;
				while (cin.fail() || finalScore<0 || finalScore>MaxScore) {
					cout << "error input(��������)\n";
					cin.clear();
					cin.ignore(65535, '\n');
					cin >> finalScore;
				}
				m_vecStudent[j].modifyScore(finalScore);
				return;
			}
		}
		cout << "��ѧ��������!\n";
	}
	else if (2 == choose) {
		cout << "������ѧ��:";
		int number;
		cin >> number;
		int j = 0;
		for (auto i = m_vecStudent.begin(); i < m_vecStudent.end(); i++, j++) {
			if (number == i->getNumber()) {
				cout << "�������޸ĺ�ĳɼ�:";
				cin >> finalScore;
				while (cin.fail() || finalScore<0 || finalScore>MaxScore) {
					cout << "error input(��������)\n";
					cin.clear();
					cin.ignore(65535, '\n');
					cin >> finalScore;
				}
				m_vecStudent[j].modifyScore(finalScore);
				return;
			}
		}
		cout << "��ѧ��������!\n";
	}
	cout << "�޸ĳɹ�\n";
}

int VecStudent::passNum()
{
	int num = 0;
	for (auto i : m_vecStudent) {//only read
		if (i.isPass()) {
			num++;
		}
	}
	return num;
}

int VecStudent::excellentNum()
{
	int num = 0;
	for (auto i : m_vecStudent) {//only read
		if (i.isExcellent()) {
			num++;
		}
	}
	return num;
}


void VecStudent::outputAllDetail(ostream& os)
{
	for (auto i : m_vecStudent) {
		os << i << endl;
	}
}


bool checkChoose(int& input) noexcept {
	while (cin.fail() || input > 7 || input < 0) {
		cout << "��������!����������\n";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> input;
	}
	return true;
}

void menu() {
	cout << endl << endl << endl << "ѧ���ɼ�����ϵͳ���˵� " << endl;
	cout << endl << endl << endl << "1.���ѧ����Ϣ " << endl;
	cout << "2.�������ѧ����Ϣ " << endl;
	cout << "3.����ѧ����Ϣ " << endl;
	cout << "4.�޸�ѧ����Ϣ " << endl;
	cout << "5.ͳ�Ƽ������� " << endl;
	cout << "6.ͳ���������� " << endl;
	cout << "7.�˳�ϵͳ " << endl;
	cout << "0.����" << endl;
	cout << endl << endl << "��ѡ��(0~7)�����س���ȷ��:";
}

int main() {
	VecStudent vec_stud;
	Student stud;
	enum menuDetail { cls, add, output, find, modify, pass_number, excellent_number, exit };
	int choose = -1;
	while (1) {
		menu();

		cin >> choose;
		checkChoose(choose);
		switch (choose) {
			case cls: {
				system("cls");
				break;
			}
			case add: {
				cin >> stud;
				vec_stud.addStud(stud);
				stud.clear();
				break;
			}
			case output: {
				vec_stud.outputAllDetail();
				break;
			}
			case find: {
				vec_stud.findStud();
				break;
			}
			case modify: {
				vec_stud.modifyScore();
				break;
			}
			case pass_number: {
				cout << "����������Ϊ:" << vec_stud.passNum() << endl;
				break;
			}
			case excellent_number: {
				cout << "����������Ϊ:" << vec_stud.excellentNum() << endl;
				break;
			}
			case exit: {
				return 0;
			}
			default: {
				break;
			}
		}
	}
		
	return 0;
}

