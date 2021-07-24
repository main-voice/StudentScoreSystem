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
		output << "学号:"<< setw(8) << setfill(' ') << setiosflags(ios::left)<<S.getNumber()
			   << "姓名:" << setw(8) << setfill(' ') << S.getName()
			   << "成绩:" << setw(4) << setfill(' ') << S.getScore();
		return output;
	}
	friend istream& operator>>(istream& input, Student& S)
	{
		int number, score;
		string name;
		cout << "请输入学生姓名\n";
		cin >> name;
		cout << "请输入学生学号\n";
		cin >> number;
		cout << "请输入学生成绩\n";
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
	cout << "请输入:按姓名查询(1)or按学号查询(2)";
	int choose;
	cin >> choose;
	while (cin.fail() || (choose != 1 && choose != 2)) {
		cout << "error input,please reinput";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> choose;
	}
	if (1 == choose) {
		cout << "请输入名字";
		string name;
		cin >> name;
		for (auto i : m_vecStudent) {
			if (name == i.getName()) {
				cout << "该学生信息为" << i;
				return;
			}
		}
		cout << "该学生不存在!\n";
		cin.clear();
		cin.ignore(65535, '\n');
	}
	else if (2 == choose) {
		cout << "请输入学号:";
		int number;
		cin >> number;
		for (auto i : m_vecStudent) {
			if (number == i.getNumber()) {
				cout << "该学生信息为:" << i;
				return;
			}
			
		}
		cout << "该学生不存在!\n";
		cin.clear();
		cin.ignore(65535, '\n');
	}
}

void VecStudent::modifyScore()
{
	int finalScore = 0;

	cout << "请输入查询方式:按姓名查询(1)or按学号查询(2)";
	int choose;
	cin >> choose;
	while (cin.fail() || (choose != 1 && choose != 2)) {
		cout << "error input,please reinput";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> choose;
	}
	if (1 == choose) {
		cout << "请输入名字:";
		string name;
		cin >> name;
		int j = 0;
		for (auto i = m_vecStudent.begin(); i < m_vecStudent.end();i++,j++) {
			if (name == i->getName()) {
				cout << "请输入修改后的成绩:";
				cin >> finalScore;
				while (cin.fail() || finalScore<0 || finalScore>MaxScore) {
					cout << "error input(错误输入)\n";
					cin.clear();
					cin.ignore(65535, '\n');
					cin >> finalScore;
				}
				m_vecStudent[j].modifyScore(finalScore);
				return;
			}
		}
		cout << "该学生不存在!\n";
	}
	else if (2 == choose) {
		cout << "请输入学号:";
		int number;
		cin >> number;
		int j = 0;
		for (auto i = m_vecStudent.begin(); i < m_vecStudent.end(); i++, j++) {
			if (number == i->getNumber()) {
				cout << "请输入修改后的成绩:";
				cin >> finalScore;
				while (cin.fail() || finalScore<0 || finalScore>MaxScore) {
					cout << "error input(错误输入)\n";
					cin.clear();
					cin.ignore(65535, '\n');
					cin >> finalScore;
				}
				m_vecStudent[j].modifyScore(finalScore);
				return;
			}
		}
		cout << "该学生不存在!\n";
	}
	cout << "修改成功\n";
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
		cout << "错误输入!请重新输入\n";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> input;
	}
	return true;
}

void menu() {
	cout << endl << endl << endl << "学生成绩管理系统主菜单 " << endl;
	cout << endl << endl << endl << "1.添加学生信息 " << endl;
	cout << "2.输出所有学生信息 " << endl;
	cout << "3.查找学生信息 " << endl;
	cout << "4.修改学生信息 " << endl;
	cout << "5.统计及格人数 " << endl;
	cout << "6.统计优秀人数 " << endl;
	cout << "7.退出系统 " << endl;
	cout << "0.清屏" << endl;
	cout << endl << endl << "请选择(0~7)并按回车键确认:";
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
				cout << "及格总人数为:" << vec_stud.passNum() << endl;
				break;
			}
			case excellent_number: {
				cout << "优秀总人数为:" << vec_stud.excellentNum() << endl;
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

