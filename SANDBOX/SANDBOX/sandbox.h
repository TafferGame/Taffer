#pragma once
#ifndef SANDBOX_H_INCLUDED
#define SANDBOX_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <iostream>

class BaseClass;
class BaseGame;
class JobClass;
class UnitClass;
class MapClass;
class PlayerClass;

enum JobType { MOVE, STAND };
//Job object.
//Contains job name. Job description.
//TODO: Job parameters. Assigned to. Location.
struct JobObject {
	char jobName[100];
	int uid;
	JobType jobType;
	JobObject * next_object;
};

class BaseClass {
public:
	bool iNumerable;
};

class BaseGame : public BaseClass {
public:
	int unitsCounter, jobCounter;
	void InitializeMap();
	void CreatePlayer();
	void PlacePlayer();
	void DrawMap();
	void CreateUnit();
	void CreateJob();
	BaseGame();
	~BaseGame();
private:
	JobClass * gameJobs;
	MapClass * gameMap;
	UnitClass * unitList;
	PlayerClass * player;
};

class JobClass : public BaseClass {
public:
	void SetJobs();
	void SetFirstJob();
	void SetNextJobs();
	JobObject * GetFirstJob();
	int EnumerateJobs();
private:
	JobObject * firstObject;
	JobObject * jobIterator;
};

class Unit : public BaseClass {
public:
	void AssignJob(JobObject*);
	JobObject * GetAssignedJob();
	int x, y;
private:
	JobObject * AssignedJob;
	int uid;
};

class PlayerClass : public BaseClass {
public:
	int currentX, currentY;
	char playerName[100];
};
#endif