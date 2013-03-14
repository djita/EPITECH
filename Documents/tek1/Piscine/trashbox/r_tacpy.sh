cat 'passwd' | sort -r | sed '{n;d}' | cut -d: -f1 | rev | sort -r | tr '\n' ',\040'
