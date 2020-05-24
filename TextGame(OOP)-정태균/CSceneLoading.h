#pragma once

#define LOADINGTEXT "                                              LOADING..."

class CSceneLoading : public CSceneBase
{
public:
	CSceneLoading();
	virtual ~CSceneLoading();

	virtual void Update();

private:
	bool _bDraw;
};

