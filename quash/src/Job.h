#ifndef JOB_H
#define JOB_H

#include "SingleJobQueue.h"

typedef int job_id_t;

typedef struct Job
{
  job_process_queue_t processQueue;
  int pipes[10][2];
  bool m_isBackground;
  job_id_t m_jobId;
  char* cmd;
} Job;

Job new_Job();

void push_process_front_to_job(Job* job, pid_t pid);

void destroy_job(Job* job);
void destroy_job_callback(Job job);

#endif
