#include <unistd.h>
#include "Job.h"

Job new_Job()
{
  Job job;
  job.my_isBackground = false;
  job.processQueue = new_job_process_queue_t(0);
  for(int i = 0; i < 10; i++)
  {
    pipe(job.pipes[i]);
  }
  return job;
}

void push_process_front_to_job(Job* job,pid_t pid)
{
  push_front_job_process_queue_t(&(job->processQueue),pid);
}

void destroy_job(Job* job)
{
  destroy_job_process_queue_t(&(job->processQueue));
  if(job->my_isBackground)
  {
    free(job->cmd);
  }
}
void destroy_job_callback(Job job)
{
  destroy_job_process_queue_t(&(job.processQueue));
  if(job.my_isBackground)
  {
    free(job.cmd);
  }
}
