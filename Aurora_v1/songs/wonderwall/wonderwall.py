# string order: EADGBe
chords = dict([
('Em'  , 'E0wA2rD2gG0wB3be3y'),
('G'   , 'E3gA2rD0wG0wB3be3y'),
('D'   , 'ExxAxxD0wG2rB3be3y'),
('A'   , 'ExxAxxD1rG1gB3be3y'),
('C'   , 'ExxA3gD2rG0wB3be3y'),
('D/F#', 'ExxA0wD0wG2rB3be3y')
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

# BPM
g.write("85")
g.write("\n")
g.write("131")
g.write("\n")

for line in f.readlines():
    line = " ".join(line.split()).split()
    for chord in line:
        tab = chords[chord]
        g.write(tab)
        g.write('\n')

f.close()
g.close()
