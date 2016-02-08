#include "application.h"

CApplication::CApplication(char *argv[]) :
	m_searchString(argv[3]),
	m_replaceString(argv[4]) {
	if (argv[1] != argv[2]) {
		m_inputFile.open(argv[1], std::ifstream::in);
		m_outputFile.open(argv[2], std::ofstream::out);
		CheckCorrectnessArgs();
		ReplaceEvent();
	}
}

CApplication::~CApplication() {
	m_inputFile.close();
	m_outputFile.close();
}

void ExitProgram() {
	system("pause");
	exit(0);
}

unsigned __int64 CheckFileSize(std::ifstream &file)  {
	std::streamoff currentSeek;
	currentSeek = file.tellg();
	file.seekg(0, file.end);
	unsigned __int64 fileLength;
	fileLength = file.tellg();
	file.seekg(currentSeek);
	return fileLength / int(pow(1024, 3));
}

void CApplication::CheckCorrectnessArgs() {
	if ((!m_inputFile) || (!m_outputFile)) {
		std::cout << "ERROR: Don't opening input or output file." << std::endl;
		ExitProgram();
	}
	else if (m_searchString == "") {
		std::cout << "ERROR: The search string is empty." << std::endl;
		ExitProgram();
	}
	if (CheckFileSize(m_inputFile) >= 2) {
		std::cout << "ERROR: Too many file size." << std::endl;
		ExitProgram();
	}
}

void CApplication::ReplaceEvent() {
	std::string currentString;
	char tempCharset[255];
	std::cout << "*_Find string: " << m_searchString.c_str() << ", Replace string: " << m_replaceString.c_str() << std::endl;
	while (!m_inputFile.eof()) {
		m_inputFile.getline(tempCharset, 255);
		currentString = tempCharset;
		std::string::size_type pos = 0;
		while ((pos = currentString.find(m_searchString, pos)) != std::string::npos) {
			currentString.replace(pos, m_searchString.size(), m_replaceString);
			pos+= m_replaceString.size();
		}
		m_outputFile << currentString.c_str() << std::endl;
		currentString = "";
	}
	std::cout << "*_Well. It's all. Have a nice day! :)" << std::endl << std::endl;
}