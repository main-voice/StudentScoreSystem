#include<iostream> 
//#include<fstream>
#include<string>
#include <vector>
#include <map>

const std::string courseName[] = { "����","��ѧ","Ӣ��","����","��ѧ","����","����","��ʷ","����" };
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
	cout << endl << endl << endl << "ѧ���ɼ�����ϵͳ���˵� " << endl;
	cout << endl << endl << endl << "1.���ѧ����Ϣ " << endl;
	cout << "2.�������ѧ����Ϣ " << endl;
	cout << "3.����ѧ����Ϣ " << endl;
	cout << "4.�޸�ѧ����Ϣ " << endl;
	cout << "5.ͳ�Ƽ������� " << endl;
	cout << "6.ͳ���������� " << endl;
	cout << "7.�˳�ϵͳ " << endl;
	cout << "0.����" << endl;
	cout << endl << endl << "��ѡ��(1~6)�����س���ȷ��:";
}

void outputAllDetail(const vector<Student> vec_refStud,ostream &os = cout) {
	for (auto i = vec_refStud.begin(); i != vec_refStud.end(); i++) {
		os << i->getNumber() << "  " << i->WhoIAm() << "  " << i->getScore();
	}
}
bool checkChoose(int& input) noexcept {
	while (cin.fail() || input > 7 || input < 0) {
		cout << "��������!����������" << endl;
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
	//freopen_s(&stream1, "ѧ���ɼ�.txt", "r", stdin);


	return 0;
}
//class student //����ѧ���� 
//{
//public: //���г�Ա
//	string name; //����
//	string sex; //�Ա�
//	int number; //ѧ��
//	int score; //����
//	int total; //�ܷ�
//	double average; //ƽ����
//	//student(); //ѧ�����캯��������ѧ�����ݵĳ�ʼ��������ѧ������
//	void add(); //���ѧ����Ϣ����
//	void output(); //���ѧ����Ϣ����
//	void find(); //����ѧ�����ݺ���
//	void modify(); //�޸�ѧ����Ϣ����
//	void stati(); //ͳ��ѧ����Ϣ����
//};
//student stu[100];
//int n = 0;
//
//void student::add() //��Ӻ��� 
//{
//	int m;
//	cout << "��������Ҫ��ӵ�ѧ������:";
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cout << "�������" << i + 1 << "��ѧ������Ϣ:" << endl;
//		cout << "ѧ��Ϊ��"; cin >> stu[i + n].number;
//		cout << "������";
//		cin >> stu[i + n].name;
//		cout << "�Ա�";
//		cin >> stu[i + n].sex;
//		cout << "�ɼ�Ϊ��";
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
////ֻ��������ѯ��û��ѧ�Ų�ѯ 
//void student::find() {//��ѯ���� 
//	int f3 = 0;
//	char n1[20];
//	student temp;
//	cout << " ������Ҫ���ҵ��˵�����: ";
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
//		cout << "�Բ���û����Ҫ���ҵ�ѧ���ɼ�" << endl;
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
//void student::modify() {//�޸ĺ��� 
//	int f4 = 0;
//	int t;
//	char n2[50];
//	cout << " ������Ҫ�޸ĵ��˵�����:";
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
//		cout << "�Բ���û����Ҫ�޸ĵ�ѧ���ɼ�" << endl;
//	else
//	{
//		cout << "������ѧ��: ";
//		cin >> stu[t].number;
//		cout << " ����: ";
//		cin >> stu[t].name;
//		cout << " �Ա� : ";
//		cin >> stu[t].sex;
//		cout << " �ɼ�: ";
//		cin >> stu[t].score;
//		stu[t].total = stu[t].score;
//		stu[t].average = stu[t].total;
//		cout << " �޸ĳɹ� !" << endl;
//	}
//	//getch(); 
//}
//void student::output() {//������� 
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
//void student::stati() {//ͳ�ƺ��� 
//	int sum1 = 0, sum2 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (stu[i].score >= 90)sum1++;
//		else if (stu[i].score >= 60)sum2++;
//	}
//	cout << "��������:" << sum2 << endl;
//	cout << "��������:" << sum1 << endl;
//}
//void menu() //�˵����� 
//{
//	cout << endl << endl << endl << "ѧ���ɼ�����ϵͳ���˵� " << endl;
//	cout << endl << endl << endl << "1.���ѧ����Ϣ " << endl;
//	cout << "2.�������ѧ����Ϣ " << endl;
//	cout << "3.����ѧ����Ϣ " << endl;
//	cout << "4.�޸�ѧ����Ϣ " << endl;
//	cout << "5.ͳ�Ƽ������������ " << endl;
//	cout << "6.�˳�ϵͳ " << endl;
//	cout << "0.����" << endl;
//	cout << endl << endl << "��ѡ��(1~6)�����س���ȷ��:";
//}
//int main() {
//	student s;
//	int choose;
//	FILE* stream1;
//	freopen_s(&stream1, "ѧ���ɼ�.txt", "r", stdin);
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
//			case 1: //�������� 
//				s.add();
//				break;
//			case 2: //��ѯ�ɼ� 
//				s.output();
//				break;
//			case 3: //�޸ĳɼ� 
//				s.find();
//				break;
//			case 4: //�������ѧ���ɼ� 
//				s.modify();
//				break;
//			case 5: //ͳ�Ƽ������������ 
//				s.stati();
//				break;
//			case 6: //�˳�ϵͳ 
//				exit(0);
//			case 0://���� 
//				system("cls");
//				menu();
//			default:
//				cout << "�����������������룡\n";
//				break;
//		}
//	} while (choose != 0);
//	//freopen("ѧ���ɼ�.txt","w",stdout);
//	for (int i = 0; i < n; i++)
//		cout << stu[i].number << " " << stu[i].name << " " << stu[i].score << endl;
//	return 0;
//}
