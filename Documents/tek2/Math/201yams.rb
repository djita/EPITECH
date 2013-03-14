#!/usr/bin/env ruby



if ARGV.size() == 6
  x = ARGV
  dices = []

  for i in x[0...5]
    dices << i.to_i
  end
  combi = x[5].split('_')

  puts dices
  puts combi
else
  puts "Usage: ./201yams X X X X X combi (X being a number)"
end
