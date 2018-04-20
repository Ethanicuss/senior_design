# string order: EADGBe
chords = dict([
('8th' , '714'),
('quarter', '1071'),
('dotquarter', '2142'),
('half', '2858'),
('whole', '5716'),
('rest', 'ExxAxxDxxGxxBxxexx'),
('E'   , 'ExxAxxDxxG3rB6ge5b'),
('D'   , 'ExxAxxDxxG5rB6ge6b'),
('A'   , 'ExxAxxDxxG5rB6ge5b'),
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
