/***********************************************************************
 * File: File.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/05/21
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/21
 * Description: Class_Inheritance File cpp
***********************************************************************/
#include "File.h"

/**

Intent: Create a File object and initialize it with the provided text and file path
Pre: A string containing the text and a string containing the file path are provided
Post: A File object is created and the text and file path are set accordingly
*/
File::File(string text, string filePath)
	:Document(text), filePath(filePath)
{
	fileOut.open(filePath);
}
/**

Intent: Set the file path of the File object
Pre: A string containing the file path is provided
Post: The file path of the File object is updated
*/
void File::setPathname(string filePath)
{
	this->filePath = filePath;
}
/**

Intent: Assign the contents of another File object to the current File object
Pre: A reference to a File object is provided
Post: The text and file path of the current File object are updated to match the contents of the other File object
*/
void File::operator=(File& file)
{
	text = file.getText();
	filePath = file.getPathname();
	fileOut.close();
	fileOut.open(filePath);
}
