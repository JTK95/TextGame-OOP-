#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneManager.h"
#include "CScreenBuffer.h"

int main()
{
	while (true)
	{
		CScreenBuffer::GetInstance()->ClearBuffer();

		CSceneManager::GetInstance()->Update();
		
		CScreenBuffer::GetInstance()->Flip();

		Sleep(16);
	}

	return 0;
}