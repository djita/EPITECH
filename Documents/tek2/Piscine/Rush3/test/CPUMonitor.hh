#ifndef CPUMONITOR_H_
#define CPUMONITOR_H_

#include <string>

class CpuMonitor : public IMonitorModule
{
public:
  CpuMonitor();
  CpuMonitor(CpuMonitor const &);
  ~CpuMonitor();

  CpuMonitor & operator=(CpuMonitor const &);
};

#endif
