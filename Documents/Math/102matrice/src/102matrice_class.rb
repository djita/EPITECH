#!/usr/bin/ruby

require 'mathn'

class MathProj
  def init(x)
    mx = Matrix[ [x[0].to_i, x[1].to_i], 
                 [x[2].to_i, x[3].to_i] ]
    return mx
  end
  
  def add(mtx_a, mtx_b)
    x = mtx_a + mtx_b
    return x
  end
  
  def const(p, mtx_a)
    x = mtx_a.collect { |e| e * p}
    return x
  end

  def vecbymatrix(mtx_a, vec)
    i = 0
    x = [0, 0]
    while mtx_a[i]
      j = 0
      while mtx_a[i][j]
        x[i] = x[i] + (vec[j] * mtx[i][j])
        j = j + 1
      end
      i = i + 1
    end
    return x
  end

  def mult(mtx_a, mtx_b)
    x = mtx_a * mtx_b
    return x
  end
end

if ARGV

  mtx = MathProj.new

  if (ARGV.first == "1")
    if (ARGV.size == 10)
      mtx_a = mtx.init(ARGV[2...6])
      mtx_b = mtx.init(ARGV[6...10])
      puts "#{mtx.add(mtx_a, mtx_b)}"
    else
      puts "Missing #{10 - ARGV.size} arguments"
    end
  end
  
  if (ARGV.first == "2")    
    if (ARGV.size == 7)
      const = ARGV[2].to_i
      mtx_a = mtx.init(ARGV[3...7])
      puts "#{mtx.const(const, mtx_a)}"
    else
      puts "Missing #{7 - ARGV.size} arguements"
    end
  end
  
  if (ARGV.first == "3")
    if (ARGV.size == 8)
      mtx_a = [ [ARGV[2].to_i, ARGV[3].to_i],
                [ARGV[4].to_i, ARGV[5].to_i] ]
      vector = [ ARGV[6].to_i, ARGV[7].to_i ]
      puts "#{mtx.vecbymtx(mtx_a, vector)}"
    else
      puts "Missing #{8 - ARGV.size} arguments"
    end
  end
  
  if (ARGV.first == "4")
    if (ARGV.size == 10)
      mtx_a = mtx.init(ARGV[2...6])
      mtx_b = mtx.init(ARGV[6...10])
      puts "AB:\n#{mtx.mult(mtx_a, mtx_b)}\n\nBA:\n#{mtx.mult(mtx_b, mtx_a)}"
    else
      puts "Missing #{10 - ARGV.size} arguments"
    end
  end
  
end
