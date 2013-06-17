def simpson(f, a, b, n)
  h = (b - a) / n
  s = f[a] + f[b]
  
  for i in (1..n).step(2)
      s += 4 * f[a + i * h]
  end
  for i in (2..n-1).step(2)
      s += 2 * f[a + i * h]
  end
  return s * h / 3
end

func = lambda { |x| x ** 9 }

print simpson(func, 0.0, 10.0, 100000)
