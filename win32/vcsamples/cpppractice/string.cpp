/**
 * 2013-03-28
 *
 * ��ʾ���дһ����ȫ����,�漰���캯�����������������ظ�ֵ������
 */

#include "String.h"

String::String(const char* str) {
	if (str != NULL) {
		int len = strlen(str);
		m_data = new char[len+1];
		strcpy(m_data, str);
		m_data[len] = '\0';
	} else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

String::String(const String& rhs) {
	int len = strlen(rhs.m_data);
	m_data = new char[len+1];
	strcpy(m_data, rhs.m_data);
	m_data[len] = '\0';
}

String& String::operator=(const String& rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete[] m_data;

	int len = strlen(rhs.m_data);
	m_data = new char[len+1];
	strcpy(m_data, rhs.m_data);
	m_data[len] = '\0';

	return *this;
}

String::~String() {
	if (m_data != NULL) {
		delete[] m_data;
		m_data = NULL;
	}
}