#pragma once
#ifndef SANDBOX_H_INCLUDED
#define SANDBOX_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <iostream>

struct JobObject {
	char job_name[100];
	char job_description[1000];
	JobObject * next_object;
};

class BaseClass {
public:
	bool iNumerable;
};

class Job : public BaseClass {
public:
	void SetJobs();
	void SetFirstJob();
	void SetNextJobs();
	int EnumerateJobs();
private:
	JobObject * first_object;
	JobObject * jo;
};

class Unit : public BaseClass {
public:
	void AssignJob(JobObject*);
	JobObject GetJob();
private:
	JobObject * AssignedJob;
};

#endif