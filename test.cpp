#include<iostream> 
//#include<fstream>
#include<string>
#include <vector>
#include <map>

const std::string courseName[] = { "语文","数学","英语","物理","化学","生物","政治","历史","地理" };
const enum enum_course { chinese, math, english, physics, chemistry, biology, political, history, geography };
using namespace std;

class Student {
public:

	int getNumber()const{
		return m_stud_num;
	}
	void setNumber(int num){
		m_stud_num = num;
	}


	void setScore(const string &course,int score) {
		int count = 0;
		if (!(count = m_score[course])) {//This score has not yet been entered
			m_score[course] = score;
		}
	}
	int getScore(string course) const{
		int count = 0;
		if (!(count = m_score[course])) {//This score has not yet been entered
			
		}
	}
	void modifyScore(const string& course,int score) {
		m_score = score;
	}

	bool isExcellent() {
		return (m_score >= 90) ? true : false;
	}
	bool isPass() {
		return (m_score >= 60) ? true : false;
	}
	string WhoIAm() const{ 
		return name;
	}//return the name of student
private:
	int m_stud_num;
	map<string, int> m_score;
	string name;
};

class VecStudent {
public:
	
private:
	vector<Student> m_vecStudent;
};
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
	cout << endl << endl << "请选择(1~6)并按回车键确认:";
}

void outputAllDetail(const vector<Student> vec_refStud,ostream &os = cout) {
	for (auto i = vec_refStud.begin(); i != vec_refStud.end(); i++) {
		os << i->getNumber() << "  " << i->WhoIAm() << "  " << i->getScore();
	}
}
bool checkChoose(int& input) noexcept {
	while (cin.fail() || input > 7 || input < 0) {
		cout << "错误输入!请重新输入" << endl;
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> input;
	}

	return true;
}

int main() {
	vector<Student> vec_stud;
	Student s;
	enum menuDetail { cls, add, output, find, modify, pass_number, exit };
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
				break;
			}
			case output: {
				outputAllDetail(vec_stud);
				break;
			}
			case find: {

			}
			case modify: {

			}
			case pass_number: {

			}
			case exit: {
				return 0;
			}
			default: {

			}
		}
	}
		
	
	//FILE* stream1;
	//freopen_s(&stream1, "学生成绩.txt", "r", stdin);


	return 0;
}
//class student //定义学生类 
//{
//public: //公有成员
//	string name; //名字
//	string sex; //性别
//	int number; //学号
//	int score; //分数
//	int total; //总分
//	double average; //平均分
//	//student(); //学生构造函数，用于学生数据的初始化及保存学生数据
//	void add(); //添加学生信息函数
//	void output(); //输出学生信息函数
//	void find(); //查找学生数据函数
//	void modify(); //修改学生信息函数
//	void stati(); //统计学生信息函数
//};
//student stu[100];
//int n = 0;
//
//void student::add() //添加函数 
//{
//	int m;
//	cout << "请输入需要添加的学生人数:";
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cout << "请输入第" << i + 1 << "个学生的信息:" << endl;
//		cout << "学号为："; cin >> stu[i + n].number;
//		cout << "姓名：";
//		cin >> stu[i + n].name;
//		cout << "性别：";
//		cin >> stu[i + n].sex;
//		cout << "成绩为：";
//		cin >> stu[i + n].score;
//	}
//	n += m;
//}
//
//int strcmp1(string a, char b[])
//{
//	int l1 = a.length(), l2 = strlen(b);
//	if (l1 != l2)return 1;
//	for (int i = 1; i <= l1; i++)
//		if (a[i - 1] != b[i - 1])return 1;
//	return 0;
//}
////只有姓名查询，没有学号查询 
//void student::find() {//查询函数 
//	int f3 = 0;
//	char n1[20];
//	student temp;
//	cout << " 输入你要查找的人的姓名: ";
//	cin >> n1;
//	for (int j = 0; j < n; j++)
//	{
//		if (strcmp1(stu[j].name, n1) == 0)
//		{
//			temp = stu[j];
//			f3 = 1;
//			break;
//		}
//	}
//	if (f3 == 0)
//		cout << "对不起，没有你要查找的学生成绩" << endl;
//	else
//	{
//		cout << " ---------------------------------------------------------------------------" << endl;
//		cout << " number name sex math C++ English total average" << endl;
//		cout << " ---------------------------------------------------------------------------" << endl;
//		cout << " " << temp.number << " " << temp.name << " " << temp.sex << " " << temp.score
//			<< " " << temp.total << " " << temp.average << endl;
//	}
//	//getch(); 
//}
//
// 
//void student::modify() {//修改函数 
//	int f4 = 0;
//	int t;
//	char n2[50];
//	cout << " 输入你要修改的人的姓名:";
//	cin >> n2;
//	for (int j = 0; j < n; j++)
//	{
//		if (strcmp1(stu[j].name, n2) == 0)
//		{
//			t = j;
//			f4 = 1;
//			break;
//		}
//	}
//	if (f4 == 0)
//		cout << "对不起，没有你要修改的学生成绩" << endl;
//	else
//	{
//		cout << "请输入学号: ";
//		cin >> stu[t].number;
//		cout << " 姓名: ";
//		cin >> stu[t].name;
//		cout << " 性别 : ";
//		cin >> stu[t].sex;
//		cout << " 成绩: ";
//		cin >> stu[t].score;
//		stu[t].total = stu[t].score;
//		stu[t].average = stu[t].total;
//		cout << " 修改成功 !" << endl;
//	}
//	//getch(); 
//}
//void student::output() {//输出函数 
//	if (n != 0)
//	{
//		cout << " ---------------------------------------------------------------------------\n";
//		cout << " number     name      sex    math    C++     English    total    average\n";
//		cout << " --------------------------------------------------------------------------- \n";
//		for (int t = 0; t < n; t++)
//		{
//			cout << stu[t].number << "     " << stu[t].name << "     " << stu[t].sex << "     " << stu[t].score << endl;
//		}
//	}
//	//getch(); 
//}
//void student::stati() {//统计函数 
//	int sum1 = 0, sum2 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (stu[i].score >= 90)sum1++;
//		else if (stu[i].score >= 60)sum2++;
//	}
//	cout << "及格人数:" << sum2 << endl;
//	cout << "优秀人数:" << sum1 << endl;
//}
//void menu() //菜单函数 
//{
//	cout << endl << endl << endl << "学生成绩管理系统主菜单 " << endl;
//	cout << endl << endl << endl << "1.添加学生信息 " << endl;
//	cout << "2.输出所有学生信息 " << endl;
//	cout << "3.查找学生信息 " << endl;
//	cout << "4.修改学生信息 " << endl;
//	cout << "5.统计及格和优秀人数 " << endl;
//	cout << "6.退出系统 " << endl;
//	cout << "0.清屏" << endl;
//	cout << endl << endl << "请选择(1~6)并按回车键确认:";
//}
//int main() {
//	student s;
//	int choose;
//	FILE* stream1;
//	freopen_s(&stream1, "学生成绩.txt", "r", stdin);
//
//	/*cin.clear();
//	cin.ignore(65535, '\n');*/
//	cout << "1111" << endl;
//	cin >> n;
//
//	if (n == 0) {
//		cout << "n is useless!!!";
//		cin >> n;
//	}
//	cout << n << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> stu[i].number >> stu[i].name >> stu[i].score;
//	}
//	//fflush(fp);
//	freopen_s(&stream1, "CON", "r", stdin);
//	do {
//		menu();
//		cin >> choose;
//		switch (choose)
//		{
//			case 1: //输入数据 
//				s.add();
//				break;
//			case 2: //查询成绩 
//				s.output();
//				break;
//			case 3: //修改成绩 
//				s.find();
//				break;
//			case 4: //输出所有学生成绩 
//				s.modify();
//				break;
//			case 5: //统计及格和优秀人数 
//				s.stati();
//				break;
//			case 6: //退出系统 
//				exit(0);
//			case 0://清屏 
//				system("cls");
//				menu();
//			default:
//				cout << "输入有误，请重新输入！\n";
//				break;
//		}
//	} while (choose != 0);
//	//freopen("学生成绩.txt","w",stdout);
//	for (int i = 0; i < n; i++)
//		cout << stu[i].number << " " << stu[i].name << " " << stu[i].score << endl;
//	return 0;
//}
