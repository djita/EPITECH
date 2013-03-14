#ifndef OSMONITOR_H_
#define OSMONITOR_H_

#include "AMonitor.hh"

class OSMonitor : public AMonitor
{
public:
  OSMonitor();
  OSMonitor(OSMonitor const &);
  ~OSMonitor();

  OSMonitor & operator=(OSMonitor const &);
};

#endif
