#include "Student.hpp"
#include <algorithm>

using namespace std;

int main(){
	const int size = 3;//������ �������
	setlocale(LC_ALL, "");
	Student students[size];//��� ������ ���������
	int a;
	while(true){
		 cout << "\n1. ������� ������\n2. ����� ����������\n3. ����� ����\n4. �����\n-> ";
		 cin >> a;
		 if(a == 1){
			 cout << "������� �������� ������ ������[5]\n";
			 try{
				 //��������� ������
				for(int i = 0; i < size; ++i){
				     cin >> students[i];
				}
				/*���������*/
				qsort(students, size, sizeof(Student), Student::cmp);
			 }
			 catch(const Exception& e){
				cout << "\n" << e.what();
			 }
		 }
		 if(a == 2){
			 bool flg = true;
			 for(int i = 0; i < size; ++i){
				if(students[i].isGoodMarks()){
					cout << "\n" << students[i];
					flg = false;
				}
			 }
			 if(flg){
				cout << "�� �������!";
			 }
		 }
		 else if(a == 3){
		   for(int i = 0; i < size; ++i){
					cout << "\n" << students[i];
			 }
		 }
		 if(a == 4){
			 return 0;
		 }
	}
}