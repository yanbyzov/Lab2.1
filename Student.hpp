#pragma once
#include "Exception.hpp"
#include <iostream>

class Student{
private:
	std::string init;//инициалы
	std::string surname;//фамили€
	std::string group;//группа
	int marks[5];//успеваемость
public:
	Student(const std::string& init = "", const std::string& surname = "", const std::string& group = "", int* marks = nullptr);
	Student(const Student& s);
	~Student();
	Student& operator=(const Student& s);//оператор присваивани€
public:
	friend std::istream& operator>>(std::istream& in, Student& s);//оператор ввода
	friend std::ostream& operator<<(std::ostream& out, const Student& s);//оператор вывода
public:
	const std::string& Init() const;
	void Init(const std::string& init);
	const std::string& Surname()const;
	void Surname(const std::string& surname);
	const std::string& Group()const;
	void Group(const std::string& group);
	void Marks(int *marks);
	int* Marks();
	//компаратор
	static int cmp(const void * a, const void *b);
	//средний балл
	double middle() const;
	//выводит, €вл€ютс€ ли оценки хорошими
	bool isGoodMarks() const;
};