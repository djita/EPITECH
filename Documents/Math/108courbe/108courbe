#!/usr/bin/env ruby

require 'gnuplot'
require 'mathn'

def plot(function)

  Gnuplot.open do |gp|
    Gnuplot::Plot.new( gp ) do |plot|

      plot.xrange "[-10:10]"
      plot.yrange "[-10:10]"
      plot.title  "108 courbe"
      plot.ylabel "x"
      plot.xlabel function
    
      plot.data << Gnuplot::DataSet.new( function ) do |ds|
        ds.with = "lines"
        ds.linewidth = 4
      end
    
    end
  
  end

end

def random_plot(option)

  if (option == 1)
    plot( "log(x)" )
  end

  if (option == 2)
    plot( "exp(x)" )
  end

  if (option == 3)
    plot( "0.5 ** x" )
  end

  if (option == 4)
    plot( "cos(x)" )
  end

  if (option == 5)
    plot( "sin(x)" )
  end

  if (option == 6)
    plot( "tan(x)" )
  end

  if (option == 7)
    plot( "cosh(x)" )
  end

  if (option == 8)
    plot( "sinh(x)" )
  end

  if (option == 9)
    plot( "tanh(x)" )
  end

end

if ARGV

  av = ARGV

  if (av[0] == '1')
    plot( "log(x)" )
  end

  if (av[0] == '2')
    plot( "exp(x)" )
  end

  if (av[0] == '3')
    plot( "0.5 ** x" )
  end

  if (av[0] == '4')
    plot( "cos(x)" )
  end

  if (av[0] == '5')
    plot( "sin(x)" )
  end

  if (av[0] == '6')
    plot( "tan(x)" )
  end

  if (av[0] == '7')
    plot( "cosh(x)" )
  end

  if (av[0] == '8')
    plot( "sinh(x)" )
  end

  if (av[0] == '9')
    plot( "tanh(x)" )
  end

  if (av[0] == '10')
    random_plot(rand(10))
  end

end
