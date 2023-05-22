/***********************************************************************
 * File: Email.cpp
 * Author: ���|�A
 * Create Date: 2023/05/21
 * Editor: ���|�A
 * Update Date: 2023/05/21
 * Description: Class_Inheritance Email cpp
***********************************************************************/
#include "Email.h"

Email::Email(string context, string sender, string receiver, string title)
	:Document(context), sender(sender), receiver(receiver), title(title)
{
	
}
