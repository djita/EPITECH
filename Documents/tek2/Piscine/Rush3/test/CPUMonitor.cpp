#include "CPUMonitor.hh"

CpuMonitor::CpuMonitor() : data("") {}
CpuMonitor::CpuMonitor(CpuMonitor const &other) : data(other.data) {}
CpuMonitor::~CpuMonitor();

std::string const & getDataSource() const
{
  // FIXME
}

std::string const & getDataSample() const
{
  // FIXME
}
