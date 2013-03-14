#ifndef KERNELMONITOR_H_
#define KERNELMONITOR_H_

class KernelMonitor : public AMonitor
{
public:
  KernelMonitor();
  KernelMonitor(KernelMonitor const &);
  ~KernelMonitor();

  KernelMonitor & operator=(KernelMonitor const &);
};

#endif
