#include "CFileIOWrapper.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstring>

namespace
{

	inline CFileIOWrap::FileHandle openFile(std::string pathToFile, const char accessType)
	{
		CFileIOWrap::FileHandle fh{ nullptr, pathToFile};

		fh.pFile = fopen(pathToFile.c_str(), &accessType);

		if( !fh.pFile )
		{
			std::stringstream ss{};
			ss <<  "Error when opening " <<  pathToFile << " : " << strerror( errno );
			throw std::runtime_error{ ss.str() };
		}

		return fh;
	}

}

namespace CFileIOWrap
{

	FileHandle openFileForReading(std::string pathToFile)
	{
		return openFile(pathToFile, 'r');
	}

	FileHandle openFileForWriting(std::string pathToFile)
	{
		return openFile(pathToFile, 'w');
	}

	void writeToFile(FileHandle& fh, std::string text)
	{
		fprintf( fh.pFile, "%s\n", text.c_str());

		if( ferror( fh.pFile ) )
		{
			std::stringstream ss{ };
			ss << "Error when writing to " << fh.path;
			throw std::runtime_error{ ss.str() };
		}
	}

	enum
	{
		MAX_CHAR_READ_BUFFER = 1024
	};

	std::string readFromFile(FileHandle& fh)
	{
		char textBuffer[MAX_CHAR_READ_BUFFER];
		std::stringstream ss{ };

		while ( fgets( textBuffer, 1024, fh.pFile) )
		{
			ss << textBuffer;
		}

		if( ferror( fh.pFile ) )
		{
			std::stringstream ss{ };
			ss << "Error when writing to " << fh.path;
			throw std::runtime_error{ ss.str() };
		}

		return std::string{ ss.str() };
	}

	void closeFile(FileHandle& fh)
	{
		if( fclose(fh.pFile) )
		{
			std::stringstream ss{ };
			ss << "Error when closing " << fh.path << " : " << strerror( errno );
			throw std::runtime_error{ ss.str() };
		}

		fh.path = "";
	}

}