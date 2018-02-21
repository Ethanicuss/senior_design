# string order: EADGBe
chords = dict([
('8th' , '357'),
('quarter', '714'),
('dotquarter', '1071'),
('half', '1429'),
('whole', '2857'),
('rest', 'ExxAxxDxxGxxBxxexx'),
('E'   , 'ExxAxxDxxG3_B6_e5_'),
('D'   , 'ExxAxxDxxG5_B6_e6_'),
('A'   , 'ExxAxxDxxG5_B6_e5_'),
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

g.write('333')
g.write('\n')

for line in f.readlines():
    line = " ".join(line.split()).split()
    for chord in line:
        tab = chords[chord]
        g.write(tab)
        g.write('\n')

f.close()
g.close()
