#include "stdafx.h"

#include "CBaseObject.h"
#include "CList.h"
#include "CPlayerObject.h"
#include "CEnemyObject.h"
#include "CPlayerBullet.h"
#include "CEnemyBullet.h"
#include "CObjectManager.h"

CObjectManager::CObjectManager()
{}

CObjectManager::~CObjectManager()
{}

CObjectManager* CObjectManager::GetInstance()
{
	static CObjectManager objectManager;

	return &objectManager;
}

//---------------------------------
// CreateObject
//---------------------------------
void CObjectManager::CreateObject(ObjectType ot, int iXpos, int iYpos)
{
	if (ot == ObjectType::PLAYER_TYPE)
	{
		objList.push_back(new CPlayerObject(iXpos, iYpos));
	}

	if (ot == ObjectType::ENEMY_TYPE)
	{
		objList.push_back(new CEnemyObject(iXpos, iYpos));
	}

	if (ot == ObjectType::PLAYER_BULLET_TYPE)
	{
		objList.push_back(new CPlayerBullet(iXpos, iYpos));
	}

	if (ot == ObjectType::ENEMY_BULLET_TYPE)
	{
		objList.push_back(new CEnemyBullet(iXpos, iYpos));
	}
}

//---------------------------------
// DestroyObject
//---------------------------------
void CObjectManager::DestroyObject(CBaseObject* destroyObject)
{
	for (this->iter = objList.begin(); this->iter != objList.end();)
	{
		if (*iter == destroyObject)
		{
			delete destroyObject;
			objList.erase(this->iter);
			break;
		}
		else
		{
			++(this->iter);
		}
	}
}

//---------------------------------
// Object 충돌 체크
//---------------------------------
void CObjectManager::CollisionCheck()
{
	for (this->iter = objList.begin(); this->iter != objList.end();)
	{
		// PlayerBullet 범위
		if ((*this->iter)->GetYpos() < 1 && (*this->iter)->GetObjectType() == 3)
		{
			CList<CBaseObject*>::CIterator nextIter;
			CPlayerBullet* pPlayerBullet = (CPlayerBullet*)(*this->iter);

			nextIter = ++(this->iter);
			pPlayerBullet->DeletePlayerBullet();
			this->iter = nextIter;
		} 
		// EnemyBullet 범위
		else if ((*this->iter)->GetYpos() > 29 && (*this->iter)->GetObjectType() == 4)
		{
			CList<CBaseObject*>::CIterator nextIter;
			CEnemyBullet* pEnemyBullet = (CEnemyBullet*)(*this->iter);

			nextIter = ++(this->iter);
			pEnemyBullet->DeleteEnemyBullet();
			this->iter = nextIter;
		}
		// PlayerObject와 EnemyBullet 충돌체크
		else if ((*this->iter)->GetObjectType() == 1) // PlayerObjectTYPE
		{
			CList<CBaseObject*>::CIterator iter2;
			CList<CBaseObject*>::CIterator nextIter;
			CPlayerObject* pPlayerObject = (CPlayerObject*)(*this->iter);

			nextIter = ++(this->iter);
			
			for (iter2 = objList.begin(); iter2 != objList.end();)
			{
				if ((*iter2)->GetObjectType() == 4) // EnemyBulletTYPE
				{
					CList<CBaseObject*>::CIterator nextEnemyBulletIter;
					CEnemyBullet* pEnemyBullet = (CEnemyBullet*)(*iter2);

					nextEnemyBulletIter = ++iter2;

					if ((pPlayerObject->GetXpos() == pEnemyBullet->GetXpos())
						&& (pPlayerObject->GetYpos() == pEnemyBullet->GetYpos()))
					{
						pPlayerObject->DeletePlayer();
						pEnemyBullet->DeleteEnemyBullet();

						iter2 = nextEnemyBulletIter;
						this->iter = nextIter;

						break;
					}
				}
				else
				{
					++iter2;
				}
			}
		}
		// EnemyObject와 PlayerBullet 충돌체크
		else if ((*this->iter)->GetObjectType() == 2) // EnemyObjectTYPE
		{
			CList<CBaseObject*>::CIterator iter2;
			CList<CBaseObject*>::CIterator nextIter;
			CEnemyObject* pEnemyObject = (CEnemyObject*)(*this->iter);

			nextIter = ++(this->iter);

			for (iter2 = objList.begin(); iter2 != objList.end();)
			{
				if ((*iter2)->GetObjectType() == 3) // PlayerObjectTYPE
				{
					CList<CBaseObject*>::CIterator nextPlayerBulletIter;
					CPlayerBullet* pPlayerBullet = (CPlayerBullet*)(*iter2);

					nextPlayerBulletIter = ++iter2;

					if ((pEnemyObject->GetXpos() == pPlayerBullet->GetXpos())
						&& (pEnemyObject->GetYpos() == pPlayerBullet->GetYpos()))
					{
						pEnemyObject->DeleteEnemy();
						pPlayerBullet->DeletePlayerBullet();

						iter2 = nextPlayerBulletIter;
						this->iter = nextIter;

						break;
					}
				}
				else
				{
					++iter2;
				}
			}
		}
		else
		{
			++(this->iter);
		}
	}
}

void CObjectManager::Update()
{
	CollisionCheck();

	for (this->iter = objList.begin(); this->iter != objList.end(); ++(this->iter))
	{
		(*iter)->Update();
	}
}

void CObjectManager::Render()
{
	for (this->iter = objList.begin(); this->iter != objList.end(); ++(this->iter))
	{
	    (*iter)->Render();
	}
}