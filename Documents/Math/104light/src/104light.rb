#!/usr/bin/ruby

require 'mathn'

## Forme: ./104light [Option] [Coordonnees du point ] [Coordonnees du vecteur] [Rayon ou Angle]

## Le calcul: Intersections de la droite avec les forme

class Numeric

  def toRadian
    return self * (Math::PI / 180)
  end

  def toDegres
    return self * (180 / Math::PI)
  end

end

def cylinder(array)

  dot = array[1...4]
  vector = array[4...7]
  radius = array[7].to_i
  dx = dot[0].to_i + vector[0].to_i
  dy = dot[1].to_i + vector[1].to_i
  dz = dot[2].to_i + vector[2].to_i
  drad = Math.sqrt((dx ** 2) + (dy ** 2))
  
  angle = Math.acos(dx / drad)

  x = Math.cos(angle)
  y = Math.sin(angle)
  z = dz

  if x != -x and y != -y
    inter = 2
  else
    inter = 1
  end

  puts("CYLINDRE de rayon R = #{radius}")
  puts("DROITE passant par le point (#{dot[0]}, #{dot[1]}, #{dot[2]}) et de vecteur directeur (#{vector[0]}, #{vector[1]}, #{vector[2]})")
  puts("Nombre de point d'intersection : #{inter}")
  puts("Point 1 : (#{sprintf("%.4f, %.4f, %.4f", x,  y, z)})")
  if inter == 2
    puts("Point 2 : (#{sprintf("%.4f, %.4f, %.4f", -x, -y, z)})")
  end

end

def sphere(array)

  dot = array[1...4]
  vector = array[4...7]
  radius = array[7].to_i
  dx = dot[0].to_i + vector[0].to_i
  dy = dot[1].to_i + vector[1].to_i
  dz = dot[2].to_i + vector[2].to_i
  drad = Math.sqrt((dx ** 2) + (dy ** 2))
  srad = Math.sqrt((dx ** 2) + (dy ** 2) + (dz ** 2))

  teta = Math.acos(dx / drad)
  phi = Math.asin(dz / srad)

  x = srad * Math.cos(phi) * Math.cos(teta) 
  y = srad * Math.cos(phi) * Math.sin(teta)
  z = srad * Math.sin(phi)

  if Math.sqrt((x ** 2) + (y ** 2) + (z ** 2)) != radius
    inter = 0
  else
    if x != -x and y != -y and z != -z
      inter = 2
    else
      inter = 1
    end
  end

  puts("SPHERE de rayon R = #{radius}")
  puts("DROITE passant par le point (#{dot[0]}, #{dot[1]}, #{dot[2]}) et de vecteur directeur (#{vector[0]}, #{vector[1]}, #{vector[2]})")
  puts("Nombre de point d'intersection : #{inter}")
  if inter > 0
    puts("Point 1 : (#{sprintf("%.4f, %.4f, %.4f", x,  y, z)})")
    if inter == 2
      puts("Point 2 : (#{sprintf("%.4f, %.4f, %.4f", -x, -y, z)})")
    end
  end

end

if ARGV

  av = ARGV
  
  if av[0] == "1"
    if av.size == 8
      cylinder(ARGV)
    end
  end
  
  if av[0] == "2"
    if av.size == 8
      sphere(ARGV)
    end
  end
  
  if av[0] == "3"
    ## cone
  end

end
