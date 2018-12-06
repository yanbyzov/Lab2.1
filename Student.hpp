#pragma once
#include "Exception.hpp"
#include <iostream>

class Student{
private:
	std::string init;//��������
	std::string surname;//�������
	std::string group;//������
	int marks[5];//������������
public:
	Student(const std::string& init = "", const std::string& surname = "", const std::string& group = "", int* marks = nullptr);
	Student(const Student& s);
	~Student();
	Student& operator=(const Student& s);//�������� ������������
public:
	friend std::istream& operator>>(std::istream& in, Student& s);//�������� �����
	friend std::ostream& operator<<(std::ostream& out, const Student& s);//�������� ������
public:
	const std::string& Init() const;
	void Init(const std::string& init);
	const std::string& Surname()const;
	void Surname(const std::string& surname);
	const std::string& Group()const;
	void Group(const std::string& group);
	void Marks(int *marks);
	int* Marks();
	//����������
	static int cmp(const void * a, const void *b);
	//������� ����
	double middle() const;
	//�������, �������� �� ������ ��������
	bool isGoodMarks() const;
};