#include <iostream>
#include <exception>      // std::exception

#include "CFileIOWrapper.hpp"
// #include "VSBTree.hpp"

int main(int argc, char* argv[])
{

	std::cout << "\n\nWrite to file: ";
	try
	{
		using namespace CFileIOWrap;

		FileHandle fh = openFileForWriting( "test.txt" );

		writeToFile( fh, "This is a test!");

		closeFile( fh );
		std::cout << " done \n";
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}

	std::cout << "\n\nRead from file: ";
	try
	{
		using namespace CFileIOWrap;

		FileHandle fh = openFileForReading( "test.txt" );

		std::cout << "\n\nContents of file: " << readFromFile( fh ) << "\n\n";

		closeFile( fh );
		std::cout << " done \n";
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}

	std::cout << "\n\nRead from unexciting file: ";
	try
	{
		using namespace CFileIOWrap;

		FileHandle fh = openFileForReading( "test2.txt" );

		std::cout << " done \n";
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}

	std::cout << "\n\nWrite to read only file: ";
	try
	{
		using namespace CFileIOWrap;

		FileHandle fh = openFileForReading( "test.txt" );

		writeToFile( fh, "This is a test!");

		closeFile( fh );
		std::cout << " done \n";
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}

	// FileHandle openFileForReading(std::string pathToFile);
	// FileHandle openFileForWriting(std::string pathToFile);

	// void writeToFile(FileHandle& fh, std::string text);
	// std::string readFromFile(FileHandle& fh);

	// void closeFile(FileHandle& fh);




	// VSBTree::BinTreeNode* root = new VSBTree::BinTreeNode{ "test" };

	// VSBTree::addNodeToTree( *root, "car");
	// VSBTree::addNodeToTree( *root, "cat");

	// const VSBTree::BinTreeNode* n = nullptr;
	// try
	// {
	// 	n = VSBTree::find( *root, "bat");
	// 	std::cout << "Found word!\n";
	// }
	// catch (std::exception& e)
	// {
	// 	std::cerr << "exception caught: " << e.what() << '\n';
	// }

	// delete root;

	return 0;
}
