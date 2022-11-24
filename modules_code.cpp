#include "modules.h"

enum class Movie::_keyType{
	GAMING,
	CARTOON
};

Movie::Movie() {
	this->_name = "";
	_key = _keyType::CARTOON;
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
	else
		return NULL;
	_tempMovie->input(_inputStream);
	return _tempMovie;
};

void Movie::input(std::ifstream& _inputStream) {
	std::string _tempString = "";
	_inputStream >> _tempString;
	this->_name = _tempString;
};

void Movie::output(std::ofstream& _outputStream) {
	_outputStream << this->_name << '\n';
};

Gaming::Gaming() {
	this->_director = NULL;
	this->_name = "";
	_key = _keyType::GAMING;
};

Gaming::~Gaming() {
	delete[] this->_director;
};

void Gaming::input(std::ifstream& _inputStream) {
	std::string _tempData = "";
	_inputStream >> this->_name >> _tempData;
	this->_director = new char[_tempData.size()+1]{'\n'};
	strcpy(this->_director, _tempData.c_str());
};

void Gaming::output(std::ofstream& _outputStream) {
	_outputStream << "This is GAMING movie with name " << this->_name << " and this director is " << this->_director << '\n';
};

Cartoon::Cartoon() {
	this->_creationMethod = typeOfCartoon::animation;
	this->_name = "";
	_key = _keyType::CARTOON;
};

Cartoon::~Cartoon() {
};

void Cartoon::input(std::ifstream& _inputStream) {
	_inputStream >> this->_name;
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
};

void Cartoon::output(std::ofstream& _outputStream) {
	_outputStream << "This is CARTOON movie with name " << this->_name << " and this creation method are ";
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

void Container::input(std::ifstream& _inputStream) {
	while (!_inputStream.eof()) {
		this->pushback(Movie::MovieIn(_inputStream));
	};
};

void Container::pushback(Movie* _inputMovie) {
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
	};
};

void Container::print(std::ofstream& _outputStream) {
	unsigned long long int _count = 0;
	ContainerNode* _current = this->_head;
	if (_current != NULL) {
		std::cout << "Skip ?\nEnter 0 if no skip, else enter\n1 if skip GAMING\n2 if skip CARTOON\n";
		int _skip = 0;
		std::cin >> _skip;
		if (_skip == 0) {
			do {
				_count++;
				_current->_data->output(_outputStream);
				_current = _current->_next;
			} while (_current != this->_head);
			_outputStream << "Total " << _count << " movies";
		}
		else if (_skip == 1) {
			do {
				if (_current->_data->_key == Movie::_keyType::CARTOON) {
					_count++;
					_current->_data->output(_outputStream);
				};
				_current = _current->_next;
			} while (_current != this->_head);
			_outputStream << "Total " << _count << " CARTOON movies";
		}
		else if (_skip == 2) {
			do {
				if (_current->_data->_key == Movie::_keyType::GAMING) {
					_count++;
					_current->_data->output(_outputStream);
				};
				_current = _current->_next;
			} while (_current != this->_head);
			_outputStream << "Total " << _count << " GAMING movies";
		};
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






