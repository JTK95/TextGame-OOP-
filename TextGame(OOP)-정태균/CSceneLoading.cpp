#include "stdafx.h"

#include "CBaseObject.h"
#include "CList.h"
#include "CObjectManager.h"
#include "CSceneBase.h"
#include "CSceneManager.h"
#include "CScreenBuffer.h"
#include "CSceneLoading.h"

//--------------------------------
// Player or Enemy �ʱ�ȭ
//--------------------------------
CSceneLoading::CSceneLoading()
{
	// Loading draw = true
	this->_bDraw = true;

	// PlayerObject ����
	int iPlayerXpos;
	int iPlayerYpos;
	
	FILE* pPlayerFile;

	fopen_s(&pPlayerFile, "PlayerInit.txt", "r");
	if (pPlayerFile == nullptr)
	{
		puts("PlayerInit.txt Open Error");
		fclose(pPlayerFile);
		return;
	}

	fscanf_s(pPlayerFile, "Player = (%d, %d)", &iPlayerXpos, &iPlayerYpos);
	CObjectManager::GetInstance()->CreateObject(ObjectType::PLAYER_TYPE, iPlayerXpos, iPlayerYpos);
	
	// EnemyObject ����
	int iEnemyXpos[ENEMY_COUNT];
	int iEnemyYpos[ENEMY_COUNT];

	FILE* pEnemyFile;
	fopen_s(&pEnemyFile, "EnemyInit.txt", "r");
	if (pEnemyFile == nullptr)
	{
		puts("EnemyInit.txt Open Error");
		fclose(pEnemyFile);
		return;
	}

	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		fscanf_s(pEnemyFile, "Enemy = (%d, %d)\n", &iEnemyXpos[i], &iEnemyYpos[i]);
		CObjectManager::GetInstance()->CreateObject(ObjectType::ENEMY_TYPE, iEnemyXpos[i], iEnemyYpos[i]);
	}

	fclose(pPlayerFile);
	fclose(pEnemyFile);
}

CSceneLoading::~CSceneLoading()
{}

// �ΰ� �����ְ� �ٷ� �� ��ȯ (��ǻ� �ε��� �ǹ̰� ������ ������Ʈ ������ ����)
void CSceneLoading::Update()
{
	static DWORD loadingTime = GetTickCount();

	if (GetTickCount() - loadingTime > 1000)
	{
		this->_bDraw = !(this->_bDraw);
		loadingTime = GetTickCount();
	}
	
	if(this->_bDraw)
	{
		CScreenBuffer::GetInstance()->DrawScene(SCREEN_HEIGHT / 2, LOADINGTEXT);
	}

	CSceneManager::GetInstance()->LoadScene(SceneList::SCENEGAME);
}

