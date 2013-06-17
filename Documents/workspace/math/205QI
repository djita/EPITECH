#!/usr/bin/env ruby

require 'gnuplot'
require 'mathn'

def simpson(f, a, b)
  return (((b - a) / 6) * (f[a] + 4 * f[(a + b) / 2] + f[b]))
end

def round2(x)
  return ((x * 10).round / 10).to_f
end

if ARGV
  av = ARGV
  sigma = 0
  mu = 0
  find = []

  ## 
  ## Options
  ##
  
  if (av.size >= 2)
    mu = av[0].to_i
    sigma = av[1].to_i
    
    if (av.size == 3)
      find = av[2].to_i
    end
    if (av.size == 4)
      find = [av[2].to_i, av[3].to_i]
    end

    ##
    ## Fonction de Repartition, Loi de Gauss (Loi normale)
    ##
    
    func = lambda { |x| ((1 / (sigma * Math::sqrt(2 * Math::PI))) * Math::exp(-(((x - mu) **  2) / (2 * (sigma ** 2))))) }

    ##
    ## Recuperation des 2 vecteurs de coordonnes
    ##
    
    xvec = (0..200).collect { |v| v.to_i }
    yvec = []
    res = 0
    for i in xvec
    res += 100 * simpson(func, i, i + 1)
      yvec << res
    end

    ##
    ## Ploting
    ##
    
    if (av.size == 2)    
      Gnuplot.open do |gp|
        Gnuplot::Plot.new( gp ) do |plot|
          
          plot.xrange "[-10:200]"
          plot.yrange "[-10:120]"
          plot.title  "205QI"
          plot.ylabel "y"
          plot.xlabel "x"
        
          plot.data << Gnuplot::DataSet.new([xvec, yvec]) { |ds|
            ds.with = "lines"
            ds.linewidth = 2
            ds.title = "repartition" }          
        end  
      end
    end

    ##
    ## Match tous inferieur a valeur
    ##
    
    if (av.size == 3)
      if (find != 0)
        puts "#{round2(yvec[find - 1])}% des personnes ont un QI inferieur a #{find}"
      else
        puts "0% des personnes ont un QI inferieur a #{find}"
      end
    end

    ##
    ## Match tous compris entre 2 valeurs
    ##
    
    if (av.size == 4 && find[0] < find[1])
      i = find[0]
      res = 0
      while (i < find[1])
        res += 100 * simpson(func, i, i + 1)
        i += 1
      end
      puts "#{round2(res)}% des personnes ont un QI compris entre #{find[0]} et #{find[1]}"
    end
  else
    puts "Usage: ./205QI [Esperance] [Variance] ([Lowerthan] | [Min Value] [Max Value])"
  end
end
