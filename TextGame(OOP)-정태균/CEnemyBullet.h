#pragma once

class CEnemyBullet : public CBaseObject
{
public:
	CEnemyBullet(int iXpos, int iYpos);
	virtual ~CEnemyBullet();

	virtual bool Update();
	virtual void Render();

	void MoveEnemyBullet();
	void DeleteEnemyBullet();

public:
	virtual int GetXpos();
	virtual int GetYpos();
};

