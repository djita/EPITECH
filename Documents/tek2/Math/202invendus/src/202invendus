##
## Author : lyoma guillou
## Project : 202invendus
## 
## This project is meant for studies purpose at EPITECH
## Please DO NOT take this as any type of implementation
## Personal use ONLY
##

#!/usr/bin/env ruby

##
## Somme des elements d'un tableau 1 dimension
##

def sum array
  x = 0
  for i in array
    x = x + i
  end
  x
end

##
## Formule du sujet
##

def formula (a, b, x, y)
  ((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150))
end

##
## Arrondissement
##

def round3 x
  return (x * 1000).round.to_i.to_f / 1000
end

##
## main
##

if ARGV.size >= 2 and ARGV[0].to_i >= 50 and ARGV[1].to_i >= 50
  a = ARGV[0].to_f
  b = ARGV[1].to_f

  price = [10.0, 20.0, 30.0, 40.0, 50.0]

  xlaw = []
  ylaw = []
  e_table = []

  ##
  ## tableau d'esperances et loi de Y
  ##

  price.each { |x| print "\tX = #{x.to_i}"}
  print "\tloi de Y\n"
  for y in price
    print "Y = #{y.to_i}"
    e_val = []
    for x in price
      val = formula(a, b, x, y)
      e_val << val
      print "\t #{sprintf("%.3f", val)}"
    end
    e_table << e_val
    ylaw << sum(e_val)
    print "\t #{sprintf("%.3f", sum(e_val))}\n"
  end

  ##
  ## loi de X
  ##

  print "loi de X"
  e_table.each_index { |i|
    e_val = []
    for x in e_table
      e_val << x[i]
    end
    xlaw << sum(e_val)
    print " #{sprintf("%.3f", sum(e_val))}\t" }
  
  if sum(xlaw).round == 1 or sum(ylaw).round == 1
    print " 1\n"
  end
  print "\n"

  ##
  ## Repartition
  ##

  z = []
  for i in price
    for j in price
      z << (i + j).to_i
    end
  end
  z = z.uniq

  zlaw = Array.new(z.size, 0)
  e_table.each_index { |i| e_table[i].each_index { |j| zlaw[i + j] += e_table[i][j] } }

  print "z"
  z.each_index { |i| print "\t#{z[i].to_i}" }
  print "\ttotal\np(Z=z)"
  zlaw.each_index { |i| print "\t#{sprintf("%.3f", zlaw[i])}" }
  print "\t#{sum(zlaw).round}\n\n"

  ##
  ## Esperances et Variances
  ##

  e_X = Array.new(xlaw.size, 0)
  v_X = Array.new(xlaw.size, 0)
  xlaw.each_index { |i| e_X[i] = (price[i] * xlaw[i]) }
  xlaw.each_index { |i| v_X[i] = ((price[i] ** 2) * (xlaw[i])) }
  e_X = sum(e_X)
  v_X = round3(sum(v_X) - (e_X ** 2))

  e_Y = Array.new(ylaw.size, 0)
  v_Y = Array.new(ylaw.size, 0)
  ylaw.each_index { |i| e_Y[i] = (price[i] * ylaw[i]) }
  ylaw.each_index { |i| v_Y[i] = ((price[i] ** 2) * (ylaw[i])) }
  e_Y = sum(e_Y)
  v_Y = round3(sum(v_Y) - (e_Y ** 2))

  e_Z = Array.new(zlaw.size, 0)
  v_Z = Array.new(zlaw.size, 0)
  zlaw.each_index { |i| e_Z[i] = (z[i] * zlaw[i]) }
  zlaw.each_index { |i| v_Z[i] = ((z[i] ** 2) * (zlaw[i])) }
  e_Z = sum(e_Z)
  v_Z = round3(sum(v_Z) - (e_Z ** 2))

  print "espérance de X : #{sprintf("%.3f", e_X)}\n"
  print "variance de X :\t #{sprintf("%.3f", v_X)}\n"

  print "espérance de Y : #{sprintf("%.3f", e_Y)}\n"
  print "variance de Y :\t #{sprintf("%.3f", v_Y)}\n"

  print "espérance de Z : #{sprintf("%.3f", e_Y)}\n"
  print "variance de Z :\t #{sprintf("%.3f", v_Z)}\n"
  
else
  puts "./202invendus a b (a et b >= 50)"
end
