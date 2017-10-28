# string order: EADGBe
chords = dict([
('Em'  , '0w2r2g0w3b3y'),
('G'   , '3g2r0w0w3b3y'),
('D'   , 'xxxx0w2r3b3y'),
('A'   , 'xxxx1r1g3b3y'),
('C'   , 'xx3g2r0w3b3y'),
('D/F#', 'xx0w0w2r3b3y')
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

# BPM
g.write("85")
g.write("\n")

for line in f.readlines():
    line = " ".join(line.split()).split()
    for chord in line:
        tab = chords[chord]
        g.write(tab)
        g.write('\n')

g.write("xxxxxxxxxxxx")

f.close()
g.close()
