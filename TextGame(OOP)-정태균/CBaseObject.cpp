#include "CBaseObject.h"


CBaseObject::CBaseObject(int iObjectType, int iXpos, int iYpos)
	:_iObjectType(iObjectType), _iXpos(iXpos), _iYpos(iYpos)
{}

CBaseObject::~CBaseObject()
{}

int CBaseObject::GetObjectType()
{
	return this->_iObjectType;
}