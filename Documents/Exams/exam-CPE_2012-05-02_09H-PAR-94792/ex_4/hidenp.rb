#!/bin/env ruby

if ARGV.size == 2
  pattern = ARGV[0]
  string = ARGV[1]
  i = 0
  j = 0

  while string[i]
    if string[i] == pattern[j]
      j = j + 1
    end
    i = i + 1
  end

  if string[i].to_i == 0 and pattern[j].to_i == 0
    puts "1"
  else
    puts "0"
  end

else
  puts "\n"
end
