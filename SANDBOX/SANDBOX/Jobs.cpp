#include "sandbox.h"


//Setting jobs for units
void JobClass::SetJobs() {
	int user_input = 0;
	firstObject = NULL;

	while (user_input != 27) {
		if (firstObject == NULL) {
			SetFirstJob();
			printf("Create more jobs? Any key to create. ESC to quit.\n");
			user_input = _getch();
		}
		else {
			SetNextJobs();
			printf("Create more jobs? Any key to create. ESC to quit.\n");
			user_input = _getch();
			system("cls");
		}
	}
}

//Setting first job in list.
void JobClass::SetFirstJob() {
	firstObject = new JobObject;
	char input;

	printf("Please, choose the job type.\n");
	std::cin.get(input);
	if (input == '1') { firstObject->jobType = MOVE; }
	else if (input == '2') { firstObject->jobType = STAND; }
	firstObject->uid = 0;

	system("cls");
}

void JobClass::SetNextJobs() {
	jobIterator = new JobObject;

	printf("Please, enter the name for the job.\n");
	std::cin.getline(jobIterator->jobName, sizeof(char[99]));
}

JobObject * JobClass::GetFirstJob()
{
	return firstObject;
}

//int JobClass::EnumerateJobs() {}

void Unit::AssignJob(JobObject * job_to_assign) {
	this->AssignedJob = NULL;
	this->AssignedJob = new JobObject;
	this->AssignedJob = job_to_assign;
}

JobObject * Unit::GetAssignedJob()
{
	return AssignedJob;
}
