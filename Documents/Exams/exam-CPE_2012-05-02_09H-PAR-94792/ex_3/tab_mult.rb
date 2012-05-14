#!/bin/env ruby

if ARGV.size == 1
  x = ARGV[0].to_i
  i = 1
  while (i <= 9)
    puts "#{i} x #{x} = #{i * x}" 
    i = i + 1
  end
else
  puts "\n"
end
