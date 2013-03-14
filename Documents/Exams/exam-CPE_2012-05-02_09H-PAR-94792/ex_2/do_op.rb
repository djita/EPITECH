#!/bin/env ruby

if ARGV.size == 3
  x = ARGV[0].to_i
  y = ARGV[2].to_i
  
  if ARGV[1] == '+'
    puts "#{x + y}"
  end
  
  if ARGV[1] == '-'
    puts "#{x - y}"
  end

  if ARGV[1] == '*'
    puts "#{x * y}"
  end

  if ARGV[1] == '/'
    puts "#{x / y}"
  end

  if ARGV[1] == '%'
    puts "#{x % y}"
  end

else
  puts "\n"
end
