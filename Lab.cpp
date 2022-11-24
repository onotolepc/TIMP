#include "modules.h"

int main(int argc, char* argv[]) {	
	std::ifstream _inputStream("input.txt");
	std::ofstream _outputStream("output.txt");
	if (!_inputStream.is_open() or !_outputStream.is_open()) {
		std::cout << "Error! Incorrect file arguments. Files cannot be open.\n";
		return 882;
	};
	std::cout << "|/| START PROGRAMM |\\|\n";
	Container* _dataContainer = new Container();
	_dataContainer->input(_inputStream);
	_inputStream.close();
	std::cout << "Filled container.\n";
	_dataContainer->sort();
	std::cout << "Sorted container.\n";
	_dataContainer->print(_outputStream);
	_dataContainer->clear();
	_dataContainer->print(_outputStream);
	std::cout << "Empty container.\n";
	_outputStream.close();
	std::cout << "|/|  END PROGRAMM  |\\|\n";
	return 0;
};
