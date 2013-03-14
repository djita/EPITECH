#ifndef TIMEMONITOR_H_
#define TIMEMONITOR_H_

#include "AMonitor.hh"

class TimeMonitor : public AMonitor
{
public:
  TimeMonitor();
  TimeMonitor(TimeMonitor const &);
  ~TimeMonitor();

  TimeMonitor & operator=(TimeMonitor const &);
}

#endif
