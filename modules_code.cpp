#include "modules.h"

Movie::Movie() {
	this->_name = "";
	this->_country = "";
};

Movie::~Movie() {
};

Movie* Movie::MovieIn(std::ifstream& _inputStream) {
	Movie* _tempMovie;
	std::string _tempString = "";
	_inputStream >> _tempString;
	if (_tempString == "CARTOON")
		_tempMovie = new Cartoon();
	else if (_tempString == "GAMING")
		_tempMovie = new Gaming();
	else if (_tempString == "DOCUMENT")
		_tempMovie = new Document();
	else
		return NULL;
	if (!_tempMovie->input(_inputStream))
		return NULL;
	else
		return _tempMovie;
	return NULL;
};

unsigned int Movie::countOfVowels() {
	unsigned long long int _count = 0;
	for (unsigned long long int i = 0; i < this->_name.size(); i++)
		if (this->_name.at(i) == 'a' || this->_name.at(i) == 'e' || this->_name.at(i) == 'i' || this->_name.at(i) == 'o' || this->_name.at(i) == 'u' || this->_name.at(i) == 'y')
			_count++;
		else if (this->_name.at(i) == 'A' || this->_name.at(i) == 'E' || this->_name.at(i) == 'I' || this->_name.at(i) == 'O' || this->_name.at(i) == 'U' || this->_name.at(i) == 'Y')
			_count++;
	return _count;
};

bool Movie::input(std::ifstream& _inputStream) {
	_inputStream >> this->_name >> this->_country;
	return true;
};

void Movie::output(std::ofstream& _outputStream) {
	if (this->_name.size() > 0 && this->_country.size() > 0)
		_outputStream << this->_name << this->_country << '\n';
	else
		return;
};

void Movie::skipCartoon(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

void Movie::skipGaming(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

void Movie::skipDocument(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

Gaming::Gaming() {
	this->_director = NULL;
	this->_name = "";
	this->_country = "";
};

Gaming::~Gaming() {
	delete[] this->_director;
};

bool Gaming::input(std::ifstream& _inputStream) {
	std::string _tempData = "";
	_inputStream >> this->_name >> this->_country >> _tempData;
	this->_director = new char[_tempData.size()+1]{'\n'};
	strcpy(this->_director, _tempData.c_str());
	if (strlen(this->_director) > 0)
		return true;
	else
		return false;
};

void Gaming::output(std::ofstream& _outputStream) {
	if (this->_name.size() > 0 && this->_country.size() > 0 && std::strlen(this->_director) > 0)
		_outputStream << "This is GAMING movie with name " << this->_name << " (Count of vowels: " << this->countOfVowels() << ") and realesed in " << this->_country << " and this director is " << this->_director << '\n';
	else
		return;
};

void Gaming::skipCartoon(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

void Gaming::skipGaming(std::ofstream& _outputStream) {
	return;
};

void Gaming::skipDocument(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

Cartoon::Cartoon() {
	this->_creationMethod = typeOfCartoon::animation;
	this->_name = "";
	this->_country = "";
};

Cartoon::~Cartoon() {
};

bool Cartoon::input(std::ifstream& _inputStream) {
	_inputStream >> this->_name >> this->_country;
	std::string _inputData = "";
	_inputStream >> _inputData;
	if (_inputData == "anime")
		this->_creationMethod = typeOfCartoon::anime;
	else if (_inputData == "animation")
		this->_creationMethod = typeOfCartoon::animation;
	else if (_inputData == "puppets")
		this->_creationMethod = typeOfCartoon::puppets;
	else if (_inputData == "plasticine")
		this->_creationMethod = typeOfCartoon::plasticine;
	else if (_inputData == "sandy")
		this->_creationMethod = typeOfCartoon::sandy;
	else
		return false;
	return true;
};

void Cartoon::output(std::ofstream& _outputStream) {
	if (this->_name.size() > 0 && this->_country.size()) {
		_outputStream << "This is CARTOON movie with name " << this->_name << " (Count of vowels: " << this->countOfVowels() << ") and realesed in " << this->_country << " and this creation method are ";
		switch (this->_creationMethod) {
		case typeOfCartoon::anime: {
			_outputStream << "anime";
			break;
		};
		case typeOfCartoon::animation: {
			_outputStream << "animation";
			break;
		};
		case typeOfCartoon::puppets: {
			_outputStream << "puppets";
			break;
		};
		case typeOfCartoon::plasticine: {
			_outputStream << "plasticine";
			break;
		};
		case typeOfCartoon::sandy: {
			_outputStream << "sandy";
			break;
		};
		};
		_outputStream << '\n';
	};
};

void Cartoon::skipCartoon(std::ofstream& _outputStream) {
	return;
};

void Cartoon::skipGaming(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

void Cartoon::skipDocument(std::ofstream& _outputStream) {
	this->output(_outputStream);
};


Document::Document() {
	this->_year = 0;
	this->_name = "";
	this->_country = "";
};

Document::~Document() {
};

bool Document::input(std::ifstream& _inputStream) {
	int _checkInt = -1;
	_inputStream >> this->_name >> this->_country >> _checkInt;
	if (_checkInt >= 0) {
		this->_year = _checkInt;
		return true;
	}
	else
		return false;
};

void Document::output(std::ofstream& _outputStream) {
	if (this->_name.size() > 0 && this->_country.size()) 
		_outputStream << "This is DOCUMENT movie with name " << this->_name << " (Count of vowels: " << this->countOfVowels() << ") and realesed in " << this->_country << " at " << this->_year << '\n';
};

void Document::skipCartoon(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

void Document::skipGaming(std::ofstream& _outputStream) {
	this->output(_outputStream);
};

void Document::skipDocument(std::ofstream& _outputStream) {
	return;
};


Container::ContainerNode::ContainerNode() {
	this->_data = NULL;
	this->_next = NULL;
	this->_prev = NULL;
};

Container::ContainerNode::~ContainerNode() {
	this->_data = NULL;
	this->_next = NULL;
	this->_prev = NULL;
};

Container::Container() {
	this->_head = NULL;
};

Container::~Container() {
	ContainerNode* _current = this->_head;
	while (_current != NULL) {
		if (_current->_next == NULL) {
			_current = NULL;
			break;
		};
		_current = _current->_next;
		_current->_prev = NULL;
	};
};

bool Container::compare(ContainerNode* _first, ContainerNode* _second) {
	if (_first->_data->countOfVowels() < _second->_data->countOfVowels())
		return true;
	else
		return false;
};

void Container::sort() {
	for (ContainerNode* _current = this->_head; (_current != this->_head->_prev && _current != NULL); _current = _current->_next) {
		for (ContainerNode* _currentSecond = _current; (_currentSecond != this->_head->_prev && _currentSecond != NULL); ) {
			_currentSecond = _currentSecond->_next;
			if (Container::compare(_current, _currentSecond)) {
				Movie* _temp = _current->_data;
				_current->_data = _currentSecond->_data;
				_currentSecond->_data = _temp;
			};
		};
	};
};

void Container::input(std::ifstream& _inputStream) {
	while (!_inputStream.eof()) {
		Movie* _tempMovie=Movie::MovieIn(_inputStream);
		if (_tempMovie == NULL)
			continue;
		else if (_tempMovie->_name.size() <= 0)
			continue;
		else if (_tempMovie->_country.size() <= 0)
			continue;
		this->pushback(_tempMovie);
	};
};

void Container::pushback(Movie* _inputMovie) {
	if (_inputMovie != NULL) {
		ContainerNode* _newNode = new ContainerNode();
		_newNode->_data = _inputMovie;
		if (this->_head == NULL) {
			this->_head = _newNode;
			this->_head->_next = this->_head;
			this->_head->_prev = this->_head;
		}
		else if (this->_head->_next == this->_head) {
			_newNode->_next = this->_head;
			this->_head->_next = _newNode;
			_newNode->_prev = this->_head;
			this->_head->_prev = _newNode;
		}
		else {
			_newNode->_prev = this->_head->_prev;
			this->_head->_prev->_next = _newNode;
			this->_head->_prev = _newNode;
			_newNode->_next = this->_head;
		}
	};
};

void Container::print(std::ofstream& _outputStream) {
	unsigned long long int _count = 0;
	ContainerNode* _current = this->_head;
	if (_current != NULL) {
		std::cout << "Skip ?\nEnter 0 if no skip, else enter\n1 if skip GAMING\n2 if skip CARTOON\n3 if skip DOCUMENT\n";
		int _skip = 0;
		std::cin >> _skip;
		do {
			if (_current == NULL)
				break;
			_count++;
			if (_skip == 0)
				_current->_data->output(_outputStream);
			else if (_skip == 1)
				_current->_data->skipGaming(_outputStream);
			else if (_skip == 2)
				_current->_data->skipCartoon(_outputStream);
			else if (_skip == 3)
				_current->_data->skipDocument(_outputStream);
			_current = _current->_next;
		} while (_current != this->_head);
		_outputStream << "Total " << _count << " movies\n\n";
	};
};

void Container::clear() {
	ContainerNode* _current = this->_head;
	while (_current != NULL) {
		ContainerNode* _next = _current->_next;
		_current->_data = NULL;
		_current->_next = NULL;
		_current->_prev = NULL;
		_current = _next;
	};
	this->_head = NULL;
};






