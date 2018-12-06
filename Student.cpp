#include "Student.hpp"

Student::Student(const std::string& init, const std::string& surname, const std::string& group, int * marks):
init(init), surname(surname), group(group){
	if(marks != nullptr){
		this->marks[0] = marks[0];
		this->marks[1] = marks[1];
		this->marks[2] = marks[2];
		this->marks[3] = marks[3];
		this->marks[4] = marks[4];
	}
	else{
		 this->marks[0] = 1;
		this->marks[1] = 1;
		this->marks[2] = 1;
		this->marks[3] = 1;
		this->marks[4] = 1;
	}
    std::cout << "\nконструктор Student"; 
}

Student::Student(const Student& s):
init(s.init), surname(s.surname), group(s.group){
	marks[0] = s.marks[0];
	marks[1] = s.marks[1];
	marks[2] = s.marks[2];
	marks[3] = s.marks[3];
	marks[4] = s.marks[4];
	 std::cout << "\nконструктор копирования Student"; 
}

Student::~Student(){ std::cout << "\nдеструктор Student"; }

Student& Student::operator=(const Student& s){//оператор присваивания
	if(this == &s){
		return *this;
	}
	init = s.init;
	surname = s.surname;
	group = s.group;
	marks[0] = s.marks[0];
	marks[1] = s.marks[1];
	marks[2] = s.marks[2];
	marks[3] = s.marks[3];
	marks[4] = s.marks[4];
	return *this;
}
//геттеры и сеттеры
const std::string& Student::Init()const{ return init; }
const std::string& Student::Surname()const{ return surname; }
const std::string& Student::Group()const{ return group; }
int* Student::Marks(){
	return marks;
}

void Student::Marks(int *marks){
	if(marks != nullptr){
		this->marks[0] = marks[0];
		this->marks[1] = marks[1];
		this->marks[2] = marks[2];
		this->marks[3] = marks[3];
		this->marks[4] = marks[4];
	}
	else{
		 this->marks[0] = 1;
		this->marks[1] = 1;
		this->marks[2] = 1;
		this->marks[3] = 1;
		this->marks[4] = 1;
	}
}

void Student::Init(const std::string& init){
	 this->init = init;
}

void Student::Group(const std::string& group){
	 this->group = group;
}

void Student::Surname(const std::string& surname){
	 this->surname = surname;
}

std::istream& operator>>(std::istream& in, Student& s){//оператор ввода
	if(!(in >> s.group >> s.surname >> s.group >> s.marks[0] >> s.marks[1] >> s.marks[2] >> s.marks[3] >> s.marks[4])){
		throw Exception("Некорректный ввод");
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Student& s){//оператор вывода
	out << s.surname << ' ' << s.init << ' ' << s.group 
		<< "\n" << s.marks[0] << ' ' << s.marks[1] << ' ' << s.marks[2] << ' ' << s.marks[3] << ' ' << s.marks[4];
	return out;
}

double Student::middle() const{
	 return (double)(marks[0] + marks[1] + marks[2] + marks[3] + marks[4]) / 5.0;
}

int Student::cmp(const void * a, const void *b){
	return ((Student*)a)->middle() > ((Student*)b)->middle();
}

bool Student::isGoodMarks() const{
	 return marks[0] >= 4 && marks[1] >= 4 &&marks[2] >= 4 &&marks[3] >= 4 &&marks[4] >= 4;
}