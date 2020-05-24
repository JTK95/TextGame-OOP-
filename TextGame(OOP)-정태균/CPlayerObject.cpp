#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneManager.h"
#include "CKeyProcess.h"
#include "CScreenBuffer.h"
#include "CBaseObject.h"
#include "CList.h"
#include "CObjectManager.h"
#include "CPlayerObject.h"

CPlayerObject::CPlayerObject(int iXpos, int iYpos)
	:CBaseObject(1, iXpos, iYpos)
{}

CPlayerObject::~CPlayerObject()
{}

bool CPlayerObject::Update()
{
	MovePlayer();

	return true;
}

void CPlayerObject::Render()
{
	CScreenBuffer::GetInstance()->DrawSprite(this->_iXpos, this->_iYpos, 'A');	
}

//----------------------------------
// MovePlayer
//----------------------------------
void CPlayerObject::MovePlayer()
{
	int iKey;

	while (true)
	{
		if (CKeyProcess::GetInstance()->MessageDeQueue(&iKey))
		{
			if (iKey == VK_UP)
			{
				if (this->_iYpos < 1)
				{
					this->_iYpos = 1;
				}

				(this->_iYpos)--;
			}

			if (iKey == VK_DOWN)
			{
				if (this->_iYpos > SCREEN_HEIGHT - 2)
				{
					this->_iYpos = SCREEN_HEIGHT - 2;
				}

				(this->_iYpos)++;
			}

			if (iKey == VK_LEFT)
			{
				if (this->_iXpos < 1)
				{
					this->_iXpos = 1;
				}

				(this->_iXpos)--;
			}

			if (iKey == VK_RIGHT)
			{
				if (this->_iXpos > SCREEN_WIDTH - 3)
				{
					this->_iXpos = SCREEN_WIDTH - 3;
				}

				(this->_iXpos)++;
			}

			// PlayerBullet »ý¼º
			if (iKey == VK_SPACE)
			{
				CObjectManager::GetInstance()->CreateObject(ObjectType::PLAYER_BULLET_TYPE, this->_iXpos, this->_iYpos);
			}
		}
		else
		{
			return;
		}
	}
}

//----------------------------------
// Player »ç¸Á -> Next Scene..
//----------------------------------
void CPlayerObject::DeletePlayer()
{
	CObjectManager::GetInstance()->DestroyObject(this);
	CSceneManager::GetInstance()->LoadScene(SceneList::SCENEOVER);
}

int CPlayerObject::GetXpos()
{
	return this->_iXpos;
}

int CPlayerObject::GetYpos()
{
	return this->_iYpos;
}