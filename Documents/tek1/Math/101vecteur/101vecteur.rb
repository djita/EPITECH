#!/usr/bin/ruby

def ScalarProduct(vectoru, vectorv, dimension)
  i = 0
  scalprod = 0

  while i < dimension
    scalprod = scalprod + (vectoru[i] * vectorv[i])
    i = i + 1
  end

  return (scalprod)
end

def VectorNorm(vector)
  i = 0
  norm = 0

  while i < 3
    norm = norm + (vector[i] ** 2)
    i = i + 1
  end

  norm = Math.sqrt(norm)
  return (norm)
end

def VectorAdd(dimension)
  i = 0
  p = rand(10)
  scalprod = 0
  vectoru = []
  vectorv = []
  puts "\nVecteur u\tVecteur v\tVecteur u + v"

  while i < dimension
    vectoru << rand(10)
    vectorv << rand(10)
    puts "    #{vectoru[i]}   \t   #{vectorv[i]}   \t\t   #{vectoru[i] + vectorv[i]}"
    i = i + 1
  end

  i = 0
  puts "\nNombre p = #{p}"
  puts "Vecteur u\tVecteur p.u"

  while i < dimension
    puts "    #{vectoru[i]}   \t   #{vectoru[i] * p}"
    i = i + 1
  end

  scalprod = ScalarProduct(vectoru, vectorv, dimension)
  puts "\nProduit scalaire (u,v) = #{scalprod}"
end

def CrossProduct
  i = 0
  uNorm = 0
  uvNorm = 0
  vectoru = []
  vectorv = []
  vectoruv = []
  puts "\nVecteur u\tVecteur v\tVecteur u * v"

  while i < 3
    vectoru << rand(10)
    vectorv << rand(10)
    i = i + 1
  end

  i = 0
  vectoruv = [(vectoru[1] * vectorv[2]) - (vectoru[2] * vectorv[1]),
              (vectoru[2] * vectorv[0]) - (vectoru[0] * vectorv[2]),
              (vectoru[0] * vectorv[1]) - (vectoru[1] * vectorv[0])]
  
  while i < 3
    puts "    #{vectoru[i]}   \t    #{vectorv[i]}   \t   #{vectoruv[i]}"
    i = i + 1
  end

  uNorm = VectorNorm(vectoru)
  uvNorm = VectorNorm(vectoruv)
  puts "\nNorme ||u|| = #{Math.sqrt(uNorm)}"
  puts "Norme ||u vect v|| = #{Math.sqrt(uvNorm)}"
end

def ScalarNormToAngle(array)  i = 0
  vectoru = []
  vectorv = []
  
  while i < 6
    if i <= 2
      vectoru << array[i]
    else
      vectorv << array[i]
    end
    i = i + 1
  end

  scalar = ScalarProduct(vectoru, vectorv, 3)
  uNorm = VectorNorm(vectoru)
  vNorm = VectorNorm(vectorv)
  angle = Math.acos(scalar/(uNorm * vNorm))
  puts "Angle (u,v) = #{angle}"
end

if ARGV
  unless (ARGV.first === ("1"..."3"))
    puts "Usage: ./101vecteur Opt(1/2/3) Params(nubmers)"
  end
  
  if (ARGV.first == "1")
    VectorAdd(ARGV.last.to_i)
  end
  
  if (ARGV.first == "2")
    unless (ARGV.size == 1)
      puts "Opt 2: No parameters will be used"
    end
    CrossProduct()
  end
  
  if (ARGV.first == "3")
    if (ARGV.size == 7)
      i = 1
      array = []

      while i <= 6
        array << ARGV[i].to_i
        i = i + 1
      end
      ScalarNormToAngle(array)
    end
  end
  
end
