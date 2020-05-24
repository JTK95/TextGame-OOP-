#pragma once


class CSceneBase
{
public:
	CSceneBase();
	virtual ~CSceneBase();

	virtual void Update() = 0;
};

