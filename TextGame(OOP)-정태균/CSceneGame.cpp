#include "stdafx.h"

#include "CScreenBuffer.h"
#include "CKeyProcess.h"
#include "CBaseObject.h"
#include "CList.h"
#include "CObjectManager.h"
#include "CSceneBase.h"
#include "CSceneGame.h"

CSceneGame::CSceneGame()
{}

CSceneGame::~CSceneGame()
{}

void CSceneGame::Update()
{
	// Ű���� �Է�
	CKeyProcess::GetInstance()->InputKey();
	
	// ������
	CObjectManager::GetInstance()->Update();

	// ��º�
	CObjectManager::GetInstance()->Render();
	CScreenBuffer::GetInstance()->Flip();
}
