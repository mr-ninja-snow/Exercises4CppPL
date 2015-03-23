#ifndef C_FILE_IO_WRAPPER_HPP
#define C_FILE_IO_WRAPPER_HPP

#include <iostream>
#include <cstdio>

namespace CFileIOWrap
{

	struct FileHandle
	{
		std::FILE* pFile;
		std::string path;
	};

	FileHandle openFileForReading(std::string pathToFile);
	FileHandle openFileForWriting(std::string pathToFile);

	void writeToFile(FileHandle& fh, std::string text);
	std::string readFromFile(FileHandle& fh);

	void closeFile(FileHandle& fh);

}

#endif