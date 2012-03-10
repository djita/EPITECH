#!/usr/bin/ruby

def show_mtx(mtx, base)

  i = 0

  while mtx[i]
    puts " #{toBaseN(mtx[i][0], base)}\t#{toBaseN(mtx[i][1], base)}"
    i = i + 1
  end

end

def show_vector(vector, base)

  i = 0

  while vector[i]
    puts " #{toBaseN(vector[i], base)}"
    i = i + 1
  end

end

def toBaseN(dec, base)

  nums = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  result = ""

  return nil if dec.instance_of? Float
  return nil if base < 2
  return 0 if dec == 0

  while dec != 0
    result += nums[dec%base].chr
    dec /= base
  end

  return result.reverse

end

def toDecN(nbr, base)

  i = 0
  x = 0
  nums = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

  return nil if nbr.instance_of? Float
  return nil if base < 2
  return 0 if nbr == 48

  while i < nbr.size
    j = 0
    while nbr[nbr.size - 1 - i] != nums[j]
      j = j + 1
    end
    x = x + (j * (base ** i))
    i = i + 1
  end

  return x
  
end

def matrix_add(array)

  base = array[1].to_i
  mtx_a = [ [ toDecN(array[2], base), toDecN(array[3], base) ], 
            [ toDecN(array[4], base), toDecN(array[5], base) ] ]
  mtx_b = [ [ toDecN(array[6], base), toDecN(array[7], base) ], 
            [ toDecN(array[8], base), toDecN(array[9], base) ] ]
  mtx_x = [ [], [] ]
  i = 0

  while mtx_a[i]
    j = 0
    while mtx_a[i][j]
      mtx_x[i][j] = mtx_a[i][j] + mtx_b[i][j]
      j = j + 1
    end
    i = i + 1
  end

  puts "Matrice A"
  show_mtx(mtx_a, base)
  puts "\nMatrice B"
  show_mtx(mtx_b, base)
  puts "\nMatrice A+B"
  show_mtx(mtx_x, base)

end

def const_by_matrix(array)

  base = array[1].to_i
  p = toDecN(array[2], base)
  mtx_a = [ [toDecN(array[3], base), toDecN(array[4], base)], 
            [toDecN(array[5], base), toDecN(array[6], base)] ]
  mtx_x = [ [], [] ]
  i = 0

  while mtx_a[i]
    j = 0
    while mtx_a[i][j]
      mtx_x[i][j] = mtx_a[i][j] * p
      j = j + 1
    end
    i = i + 1
  end

  puts "Matrice A"
  show_mtx(mtx_a, base)
  puts"\nMatrice p.A"
  show_mtx(mtx_x, base)

end

def vector_by_matrix(array)

  base = array[1].to_i
  mtx_a = [ [toDecN(array[2], base), toDecN(array[3], base)], 
            [toDecN(array[4], base), toDecN(array[5], base)] ]
  vectorU = [toDecN(array[6], base), toDecN(array[7], base)]
  vector = [0, 0]
  i = 0

  while mtx_a[i]
    j = 0
    while mtx_a[i][j]
      vector[i] = vector[i] + (vectorU[j] * mtx_a[i][j])
      j = j + 1
    end
    i = i + 1
  end

  puts "Matrice A"
  show_mtx(mtx_a, base)
  puts "\nVecteur u"
  show_vector(vectorU, base)
  puts "\nVecteur A.u"
  show_vector(vector, base)

end

def matrix_by_matrix(array)

  base = array[1].to_i
  mtx_a = [ [toDecN(array[2], base), toDecN(array[3], base)],
            [toDecN(array[4], base), toDecN(array[5], base)] ]
  mtx_b = [ [toDecN(array[6], base), toDecN(array[7], base)],
            [toDecN(array[8], base), toDecN(array[9], base)] ]
  mtx_ab = [ [0, 0], [0, 0] ]
  mtx_ba = [ [0, 0], [0, 0] ]
  i = 0

  while i < 2
    j = 0
    while j < 2
      sum_ab = 0
      sum_ba = 0
      k = 0
      while k < 2
        sum_ab = sum_ab + (mtx_a[i][k] * mtx_b[k][j])
        sum_ba = sum_ba + (mtx_b[i][k] * mtx_a[k][j])
        k = k + 1
      end
      mtx_ab[i][j] = sum_ab
      mtx_ba[i][j] = sum_ba
      j = j + 1
    end
    i = i + 1
  end

  puts "Matrice A"
  show_mtx(mtx_a, base)
  puts "\nMatrice B"
  show_mtx(mtx_b, base)
  puts "\nMatrice A.B"
  show_mtx(mtx_ab, base)
  puts "\nMatrice B.A"
  show_mtx(mtx_ba, base)

end

if ARGV

  if (ARGV.first == "1")
    if (ARGV.size == 10)
      matrix_add(ARGV)
    else
      puts "Missing #{10 - ARGV.size} arguments"
    end
  end
  
  if (ARGV.first == "2")
    if (ARGV.size == 7)
      const_by_matrix(ARGV)
    else
      puts "Missing #{7 - ARGV.size} arguements"
    end
  end
    
  if (ARGV.first == "3")
    if (ARGV.size == 8)
      vector_by_matrix(ARGV)
    else
      puts "Missing #{8 - ARGV.size} arguments"
    end
  end
  
  if (ARGV.first == "4")
    if (ARGV.size == 10)
      matrix_by_matrix(ARGV)
    else
      puts "Missing #{10 - ARGV.size} arguments"
    end
  end
  
end
