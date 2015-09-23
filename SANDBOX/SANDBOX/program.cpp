#include "sandbox.h"
#include "map.h"

int main() {
	/*Job * job = new Job;

	job->iNumerable = true;
	if (job->iNumerable == true) { printf("Job is numerable!\n"); }
	job->SetJobs();

	int job_count = job->EnumerateJobs();

	printf("You have %d jobs.\n", job_count);*/
	
	Map * map = new  Map;
	map->TestNodes();

	system("pause");
}
