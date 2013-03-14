#ifndef HOSTMONITOR_H_
#define HOSTMONITOR_H_

class HostMonitor : public IMonitorModule
{
public:
  HostMonitor();
  HostMonitor(HostMonitor const &);
  ~HostMonitor();

  HostMonitor & operator=(HostMonitor const &);
};

#endif
