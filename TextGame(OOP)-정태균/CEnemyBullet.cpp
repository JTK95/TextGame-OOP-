#include "stdafx.h"

#include "CScreenBuffer.h"
#include "CBaseObject.h"
#include "CList.h"
#include "CObjectManager.h"
#include "CEnemyBullet.h"


CEnemyBullet::CEnemyBullet(int iXpos, int iYpos)
	:CBaseObject(4, iXpos, iYpos)
{}

CEnemyBullet::~CEnemyBullet()
{}

bool CEnemyBullet::Update()
{
	MoveEnemyBullet();

	return true;
}

void CEnemyBullet::Render()
{
	CScreenBuffer::GetInstance()->DrawSprite(this->_iXpos, this->_iYpos, '!');
}

void CEnemyBullet::MoveEnemyBullet()
{
	(this->_iYpos)++;
}

//-------------------------------
// EnemyBullet »èÁ¦
//-------------------------------
void CEnemyBullet::DeleteEnemyBullet()
{
	CObjectManager::GetInstance()->DestroyObject(this);	
}

int CEnemyBullet::GetXpos()
{
	return this->_iXpos;
}

int CEnemyBullet::GetYpos()
{
	return this->_iYpos;
}