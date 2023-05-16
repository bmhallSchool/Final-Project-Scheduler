#include <list>
#include <queue>
#include <string>

using namespace std;

typedef struct Process Process;
struct Process {
  int status;
  int arrival;
  int first_run;
  int duration;
  int completion;
};

class ArrivalComparator {
 public:
  bool operator()(const Process lhs, const Process rhs) const {
    if (lhs.arrival != rhs.arrival)
      return lhs.arrival > rhs.arrival;
    else
      return lhs.duration > rhs.duration;
  }
};

class DurationComparator {
 public:
  bool operator()(const Process lhs, const Process rhs) const {
    if (lhs.duration != rhs.duration)
      return lhs.duration > rhs.duration;
    else
      return lhs.arrival > rhs.arrival;
  }
};

class LongestComparator {
public:
  bool operator()(const Process lhs, const Process rhs) const {
    if (lhs.duration != rhs.duration)
      return lhs.duration < rhs.duration;
    else
      return lhs.arrival < rhs.arrival;
  }
};

class JobComparator {
public:
  bool operator()(const Process lhs, const Process rhs) const {
    if (lhs.status != rhs.status)
      return lhs.status > rhs.status;
    else
      return lhs.arrival > rhs.arrival;
  }
};

typedef priority_queue<Process, vector<Process>, ArrivalComparator>
pqueue_arrival;
typedef priority_queue<Process, vector<Process>, DurationComparator>
pqueue_duration;
typedef priority_queue<Process, vector<Process>, LongestComparator>
pqueue_durLong;
typedef priority_queue<Process, vector<Process>, JobComparator>
pqueue_jobStatus;

pqueue_arrival read_workload(string filename);
void show_workload(pqueue_arrival workload);
void show_processes(list<Process> processes);

list<Process> fifo(pqueue_arrival workload);
list<Process> sjf(pqueue_arrival workload);
list<Process> stcf(pqueue_arrival workload);
list<Process> rr(pqueue_arrival workload);
list<Process> ljf(pqueue_arrival workload);
list<Process> ltcf(pqueue_arrival workload);
list<Process> pbs(pqueue_arrival workload);
list<Process> mlfqFive(pqueue_arrival workload);
list<Process> mlfqTen(pqueue_arrival workload);

float avg_turnaround(list<Process> processes);
float avg_response(list<Process> processes);
float avg_first_comp(list<Process> processes);
void show_metrics(list<Process> processes);
