#!/usr/bin/env ruby -w                                                          
require 'mathn'

def integ(precision)

end

if ARGV

  av = ARGV
  if av[0].to_i >= 10 or av[0].to_i <= 100
    integ(av[0].to_i)
  end

end
