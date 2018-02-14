# string order: EADGBe
chords = dict([
('E'   , 'ExxAxxD2gG1rB0we0w'),
('D'   , 'ExxAxxD0wG2rB3be2g'),
('A'   , 'ExxA0wD2rG2gB2be0w'),
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

# BPM
g.write('84')
g.write('\n')
g.write('185')
g.write('\n')

for line in f.readlines():
    line = " ".join(line.split()).split()
    for chord in line:
        tab = chords[chord]
        g.write(tab)
        g.write('\n')

g.write("xxxxxxxxxxxxxxxxx")

f.close()
g.close()
