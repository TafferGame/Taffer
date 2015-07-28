#pragma once
#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

#define _CRT_SECURE_NO_WARNINGS

//Entites should be anything: trees, rocks, units, towns.
#define MAX_ENTITIES_ON_MAP 64

#define TAFF_OK 1
#define TAFF_NULL_RESULT 2

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <conio.h>

//Engine namespaces
namespace TAFF{
	//Engine typedefs
	typedef enum
	{
		TAFF_NODE_OBJECT = 0
	} TAFF_OBJECT_TYPE;

	typedef int TAFFRESULT;

	class ITaff;

	//Engine classes declarations
	class ITaffFactory;
	class FactoryObject;
	class TaffNodeObject;

	TAFFRESULT CreateTaffFactory(ITaffFactory **ppTaffFactory);
	
}

template <typename Interface>
void TaffRelease(Interface ** ppInterfaceToRelease)
{
	if (*ppInterfaceToRelease != NULL) {
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

template void TaffRelease<TAFF::ITaff>(TAFF::ITaff ** ppInterfaceToRelease);

class TAFF::ITaff{
public:
	void Release() { delete this; }
};

//************************************FACTORY*********************************************************************
class TAFF::ITaffFactory : public TAFF::ITaff{
public:
	virtual TAFF::TAFFRESULT CreateTaffObject(TAFF::TAFF_OBJECT_TYPE tot, TaffNodeObject **ppTaffObject) = 0;
	void Release() { delete this; }
};

class TAFF::FactoryObject : public TAFF::ITaffFactory{
public:
	TAFF::TAFFRESULT CreateTaffObject(TAFF::TAFF_OBJECT_TYPE tot, TaffNodeObject **ppTaffObject);
	void Release() { delete this; }
};
//************************************OBJECTS**********************************************************************

class TAFF::TaffNodeObject : public TAFF::ITaff{

public:
	void SetObjCoordinates(float x, float y);
	void GetObjCoordinates(float *x, float *y);
	void GetNextObj(TaffNodeObject *tObjectToGet);
	void Release() { delete this; }
	void setBooleanParams(bool town);
	void getBooleanParams(bool * town);

	TaffNodeObject *nextObject;

private:
	float objX, objY;
	bool isTown;

};

#endif