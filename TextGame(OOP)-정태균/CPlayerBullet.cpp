#include "stdafx.h"

#include "CScreenBuffer.h"
#include "CBaseObject.h"
#include "CList.h"
#include "CObjectManager.h"
#include "CPlayerBullet.h"


CPlayerBullet::CPlayerBullet(int iXpos, int iYpos)
	:CBaseObject(3, iXpos, iYpos)
{}

CPlayerBullet::~CPlayerBullet()
{}

bool CPlayerBullet::Update()
{
	MovePlayerBullet();

	return true;
}

void CPlayerBullet::Render()
{
	CScreenBuffer::GetInstance()->DrawSprite(_iXpos, _iYpos, '!');
}

void CPlayerBullet::MovePlayerBullet()
{	
	(this->_iYpos)--;
}

//------------------------------
// PlayerBullet »èÁ¦
//------------------------------
void CPlayerBullet::DeletePlayerBullet()
{
	CObjectManager::GetInstance()->DestroyObject(this);
}

int CPlayerBullet::GetXpos()
{
	return this->_iXpos;
}

int CPlayerBullet::GetYpos()
{
	return this->_iYpos;
}
