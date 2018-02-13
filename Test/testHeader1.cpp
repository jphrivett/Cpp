#include "testHeader1.h"
#include "testHeader2.h"
#include <iostream>

void Display::displayItem(Storage &storage)
{
	if (m_displayIntFirst)
		std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
	else // display double first
		std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
}
