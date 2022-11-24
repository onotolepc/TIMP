#define _CRT_SECURE_NO_WARNINGS
#ifndef __MODULES__
#define __MODULES__

#include <string>
#include <iostream>
#include <fstream>

class Movie {
public:
	static Movie* MovieIn(std::ifstream& _inputStream);
	std::string _name;
	std::string _country;
	Movie();
	~Movie();
	unsigned int countOfVowels();
	virtual bool input(std::ifstream& _inputStream);
	virtual void output(std::ofstream& _outputStream);
	virtual void skipCartoon(std::ofstream& _outputStream);
	virtual void skipGaming(std::ofstream& _outputStream);
	virtual void skipDocument(std::ofstream& _outputStream);
};

class Gaming : public Movie {
private:
	char* _director;
public:
	Gaming();
	~Gaming();
	bool input(std::ifstream& _inputStream);
	void output(std::ofstream& _outputStream);
	void skipCartoon(std::ofstream& _outputStream);
	void skipGaming(std::ofstream& _outputStream);
	void skipDocument(std::ofstream& _outputStream);;
};

class Cartoon : public Movie {
private:
	enum class typeOfCartoon {
		anime,
		animation,
		puppets,
		plasticine,
		sandy
	};
	typeOfCartoon _creationMethod;
public:
	Cartoon();
	~Cartoon();
	bool input(std::ifstream& _inputStream);
	void output(std::ofstream& _outputStream);
	void skipCartoon(std::ofstream& _outputStream);
	void skipGaming(std::ofstream& _outputStream);
	void skipDocument(std::ofstream& _outputStream);
};

class Document : public Movie {
private:
	unsigned int _year;
public:
	Document();
	~Document();
	bool input(std::ifstream& _inputStream);
	void output(std::ofstream& _outputStream);
	void skipCartoon(std::ofstream& _outputStream);
	void skipGaming(std::ofstream& _outputStream);
	void skipDocument(std::ofstream& _outputStream);
};

class Container {
public:
	Container();
	~Container();
	void sort();
	void input(std::ifstream& _inputStream);
	void pushback(Movie* _inputMovie);
	void print(std::ofstream& _outputStream);
	void clear();
private:
	class ContainerNode {
	public:
		ContainerNode();
		~ContainerNode();
		Movie* _data;
		ContainerNode* _next;
		ContainerNode* _prev;
	};
	ContainerNode* _head;
	bool compare(ContainerNode* _first, ContainerNode* _second);
};

#endif // !__MODULES__

