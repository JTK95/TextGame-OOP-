#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneManager.h"
#include "CScreenBuffer.h"
#include "CBaseObject.h"
#include "CList.h"
#include "CObjectManager.h"
#include "CEnemyObject.h"

CEnemyObject::CEnemyObject(int iXpos, int iYpos)
	:CBaseObject(2, iXpos, iYpos), _iMoveCnt(5)
{
	this->_bMoveDirection = true;
}

CEnemyObject::~CEnemyObject()
{}

bool CEnemyObject::Update()
{
	MoveEnemy();
	AttackEnemy();
	return true;
}

void CEnemyObject::Render()
{
	CScreenBuffer::GetInstance()->DrawSprite(this->_iXpos, this->_iYpos, '#');
}

void CEnemyObject::MoveEnemy()
{
	if (this->_bMoveDirection)
	{
		(this->_iXpos)--;
	}
	else
	{
		(this->_iXpos)++;
	}

	(this->_iMoveCnt)--;
	if (this->_iMoveCnt == 0)
	{
		this->_iMoveCnt = 5;
		
		this->_bMoveDirection = !(this->_bMoveDirection);
	}
}

//----------------------------------------
// 2%ÀÇ È®·ü·Î EnemyBullet »ý¼º
//----------------------------------------
void CEnemyObject::AttackEnemy()
{
	if (rand() % 100 < 2)
	{
		CObjectManager::GetInstance()->CreateObject(ObjectType::ENEMY_BULLET_TYPE, this->_iXpos, this->_iYpos);
	}
}

void CEnemyObject::DeleteEnemy()
{
	static int iEnemyNum = ENEMY_COUNT;

	CObjectManager::GetInstance()->DestroyObject(this);

	// ¸ðµç Enemy°¡ »ç¸ÁÇÏ¸é ¾À ÀüÈ¯
	--iEnemyNum;
	if (iEnemyNum == 0)
	{
		CSceneManager::GetInstance()->LoadScene(SceneList::SCENEOVER);
	}
}

int CEnemyObject::GetXpos()
{
	return this->_iXpos;
}

int CEnemyObject::GetYpos()
{
	return this->_iYpos;
}
