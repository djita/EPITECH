#!/usr/bin/ruby

require 'mathn'

class Numeric

  def toRadian
    return self * (Math::PI / 180)
  end

end

def init_mtx

  mtx = [ [ 1.000, 0.000, 0.000], 
          [ 0.000, 1.000, 0.000], 
          [ 0.000, 0.000, 1.000] ]
  return mtx

end

def show_mtx(mtx)

  i = 0

  puts ("Matrice resultat:\n\n")
  while mtx[i]
    puts("#{sprintf("% 9.3f% 9.3f% 9.3f\n", mtx[i][0], mtx[i][1], mtx[i][2])}")
    i = i + 1
  end

end

def matrix_by_matrix(mtx_a, mtx_b)

  i = 0
  j = 0
  k = 0
  mtx_ab = [ [0.000, 0.000, 0.000],
             [0.000, 0.000, 0.000],
             [0.000, 0.000, 0.000] ]

  while i < 3
    j = 0
    while j < 3
      sum_ab = 0
      k = 0
      while k < 3
        sum_ab = sum_ab + (mtx_a[i][k] * mtx_b[k][j])
        k = k + 1
      end
      mtx_ab[i][j] = sum_ab
      j = j + 1
    end
    i = i + 1
  end

  return mtx_ab

end

def translate(mtx, x, y)

  mtx[0][2] = mtx[0][2] + x
  mtx[1][2] = mtx[1][2] + y
  puts ("Translation de vecteur(#{x.to_i}, #{y.to_i})")
  return mtx

end

def homothety(mtx, x, y)

  i = 0
  j = 0

  while mtx[i]
    j = 0
    while mtx[i][j]
      if i == 0
        mtx[i][j] = mtx[i][j] * x
      end
      if i == 1
        mtx[i][j] = mtx[i][j] * y
      end
      j = j + 1
    end
    i = i + 1
  end

  puts ("Homothetie de rapports #{x.to_i} et #{y.to_i}")
  return mtx

end

def rotate(mtx_x, angle)

  teta = angle.toRadian
  mtx = init_mtx
  mtx[0][0] = Math.cos(teta)
  mtx[0][1] = Math.sin(teta) * -1
  mtx[1][0] = Math.sin(teta)
  mtx[1][1] = Math.cos(teta)
  mtx = matrix_by_matrix(mtx, mtx_x)
  puts ("Rotation d'angle #{angle.to_i}")
  return mtx

end

def symetry(mtx_x, angle)

  teta = angle.toRadian
  mtx = init_mtx
  mtx[0][0] = Math.cos(2 * teta)
  mtx[0][1] = Math.sin(2 * teta)
  mtx[1][0] = Math.sin(2 * teta)
  mtx[1][1] = Math.cos(2 * teta) * -1
  mtx = matrix_by_matrix(mtx, mtx_x)
  puts ("Symetrie par rapport a un axe incline de #{angle.to_i}")
  return mtx

end

if ARGV
  
  i = 0
  mtx = init_mtx
  av = ARGV

  while (av[i])

    if (av[i] == 'T')
      mtx = translate(mtx, av[i + 1].to_f, av[i + 2].to_f)
      i = i + 2
    end
    
    if (av[i] == 'H')
      mtx = homothety(mtx, av[i + 1].to_f, av[i + 2].to_f)
      i = i + 2
    end
    
    if (av[i] == 'R')
      mtx = rotate(mtx, av[i + 1].to_f)
      i = i + 1
    end

    if (av[i] == 'S')
      mtx = symetry(mtx, av[i + 1].to_f)
      i = i + 1
    end

    i = i + 1

  end

  show_mtx(mtx)
  
end
