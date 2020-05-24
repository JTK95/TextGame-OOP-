#include "stdafx.h"

#include "CKeyProcess.h"

CKeyProcess::CKeyProcess()
	:_iFront(0), _iRear(0)
{}

CKeyProcess::~CKeyProcess()
{}

CKeyProcess* CKeyProcess::GetInstance()
{
	static CKeyProcess keyProcess;

	return &keyProcess;
}

//-------------------------------
// Message EnQueue
//-------------------------------
bool CKeyProcess::MessageEnQueue(int iKey)
{
	// 원형 큐 Full
	if (((this->_iRear + 1) % QUEUE_SIZE) == (this->_iFront))
	{
		return false;
	}

	this->_iRear = (this->_iRear + 1) % QUEUE_SIZE;
	this->_queArr[this->_iRear] = iKey;

	return true;
}

//-------------------------------
// Message DeQueue
//-------------------------------
bool CKeyProcess::MessageDeQueue(int* pKey)
{
	// 원형 큐 Empty
	if (this->_iFront == this->_iRear)
	{
		return false;
	}

	this->_iFront = (this->_iFront + 1) % QUEUE_SIZE;
	*pKey = this->_queArr[this->_iFront];

	return true;
}

//-------------------------------
// 키보드 입력
//-------------------------------
void CKeyProcess::InputKey()
{
	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		MessageEnQueue(VK_UP);
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		MessageEnQueue(VK_DOWN);
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		MessageEnQueue(VK_LEFT);
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		MessageEnQueue(VK_RIGHT);
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		MessageEnQueue(VK_SPACE);
	}
}

