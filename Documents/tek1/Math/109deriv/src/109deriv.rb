#!/usr/bin/env ruby -w

require 'gtk2'
require 'mathn'

$height = 500
$width = 500
$pading = 5

$a = 0
$n = 0
$vt = []
$vx = []

class Numeric

  def toRadian
    return self * (Math::PI / 180)
  end

end

if ARGV
  av = ARGV
  if (!av[0] or !av[1])
    puts "Usage: ./109deriv [function] [precision]"
    exit
  end

  $n = av[1].to_f
  h = 1.0 / $n
  t = 0.0
  x = 0.0
  i = 1.0

  ## f(t,x) = x ** 2
  ## a = 3/4
  ## x(t) = 3 / (4 - 3t)
  if (av[0].to_i == 1)
    $a = 3.0 / 4.0
    $vt << [0.0, $a]
    $vx << [$a, $a ** 2]
    while (i != $n)
      t = i * h
      $vt << [t, 3.0 / (4.0 - 3.0 * t)]
      x = $vt[i][1]
      $vx << [x, x ** 2.0]
      i = i + 1.0
    end
  end

  ## f(t,x) = 5/4 * x
  ## a = 1
  ## x(t) = e ** ((5 * t) / 4)
  if (av[0].to_i == 2)
    $a = 1.0
    $vt << [0.0, $a]
    $vx << [$a, (5.0 / 4.0) * $a]
    while (i != $n)
      t = i * h
      $vt << [t, Math::E ** (5.0 * t / 4.0)]
      x = $vt[i][1]
      $vx << [x, 5.0 * x / 4.0]
      i = i + 1.0
    end
  end

  ## f(t,x) = 3/2 * cos(t).x
  ## a = 1
  ## x(t) = e ** ((3 * sin(t)) / 2)
  if (av[0].to_i == 3)
    $a = 1.0
    $vt << [0.0, $a]
    $vx << [$a, (3.0 / 2.0) * Math::cos(0) * $a]
    while (i != $n)
      t = i * h
      $vt << [t, Math::E ** (3.0 * Math::sin(t) / 2.0)]
      x = $vt[i][1]
      $vx << [x, (3.0 * Math::cos(t) * x) / 2.0]
      i = i + 1.0
    end
  end

  ## f(t,x) = 2 * (cos(t) - t * tan(t ** 2) * x
  ## a = 1
  ## x(t) = e ** (2 * sin(t)) * cos(t ** 2)
  if (av[0].to_i == 4)
    $a = 1.0
    $vt << [0.0, $a]
    $vx << [$a, 2.0 * ((Math::cos(0.0) - 0.0) * Math::tan(0.0 ** 2.0)) * $a]
    while (i != $n)
      t = i * h
      $vt << [t, Math::E ** (2.0 * Math::sin(t)) * Math::cos(t ** 2.0)]
      x = $vt[i][1]
      $vx << [x, 2.0 * (Math::cos(t) - (t * Math::tan(t ** 2.0))) * x]
      i = i + 1.0
    end
  end    
end

window = Gtk::Window.new('109deriv')
window.set_default_size($height, $width)

window.signal_connect("delete_event") do
  puts "delete event occured"
  false
end

window.signal_connect("destroy") do
  Gtk.main_quit
end

area = Gtk::DrawingArea.new
area.set_size_request($height, $width)

area.signal_connect('expose_event') do
  alloc = area.allocation
  x_unit = $width / $pading
  y_unit = $height / $pading
  grid = []
  
  while (x_unit <= $width)
    grid << [x_unit, 0, x_unit, $height]
    x_unit = x_unit + ($width / $pading)
  end
  while (y_unit < $height)
    grid << [0, y_unit, $width, y_unit]
    y_unit = y_unit + ($height / $pading)
  end
  
##  area.window.draw_segments(area.style.fg_gc(area.state), grid)

  if ($vt and $vx)
    i = 0
    while ($vt[i] and $vx[i])
      $vt[i][0] = $vt[i][0] * 25.0
      $vt[i][1] = $vt[i][1] * 10.0

      $vx[i][0] = ($vx[i][0] - $a) * 25.0
      $vx[i][1] = $vx[i][1] * 5.0 + 10
      i = i + 1
    end
    area.window.draw_lines(area.style.fg_gc(area.state), $vt)
    area.window.draw_lines(area.style.fg_gc(area.state), $vx)
  end
end

window.add(area)
window.show_all

Gtk.main
