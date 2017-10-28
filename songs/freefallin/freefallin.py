# string order: EADGBe
chords = dict([
('E'   , 'xxxx2g1r0w0w'),
('D'   , 'xxxx0w2r3b2g'),
('A'   , 'xx0w2r2g2b0w'),
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

# BPM
g.write('84')
g.write('\n')

for line in f.readlines():
    line = " ".join(line.split()).split()
    for chord in line:
        tab = chords[chord]
        g.write(tab)
        g.write('\n')

g.write('xxxxxxxxxxxx')

f.close()
g.close()
