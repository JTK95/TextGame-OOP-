#pragma once

//-------------------------------
// Message ť ������
//-------------------------------
#define	QUEUE_SIZE 10

//-------------------------
// Ű���� �Է� (Singleton)
//-------------------------
class CKeyProcess
{
public:
	static CKeyProcess* GetInstance();

public:
	bool MessageEnQueue(int iKey);
	bool MessageDeQueue(int* pKey);

	void InputKey();

private:
	CKeyProcess();
	~CKeyProcess();

private:
	// MessageQueue
	int _iFront;
	int _iRear;
	int _queArr[QUEUE_SIZE];
};