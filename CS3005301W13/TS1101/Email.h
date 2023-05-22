/***********************************************************************
 * File: Email.h
 * Author: ³¯©|¿A
 * Create Date: 2023/05/21
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/21
 * Description: Class_Inheritance Email header
***********************************************************************/
#pragma once
#include "Document.h"
#include <iostream>
using namespace std;

class Email : public Document
{
public:
	Email(string context, string sender, string receiver, string title);
	string getSender() { return sender; };
	string getRecipient() { return receiver; };
	string getTitle() { return title; };
private:
	string sender;
	string receiver;
	string title;
};