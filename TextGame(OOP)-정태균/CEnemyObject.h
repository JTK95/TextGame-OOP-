#pragma once

class CEnemyObject : public CBaseObject
{
public:
	CEnemyObject(int iXpos, int iYpos);
	virtual ~CEnemyObject();

	virtual bool Update();
	virtual void Render();

	void MoveEnemy();
	void AttackEnemy();
	void DeleteEnemy();

public:
	virtual int GetXpos();
	virtual int GetYpos();

private:
	int _iMoveCnt;

	// true 왼쪽 방향, false 오른쪽 방향
	bool _bMoveDirection;
};

