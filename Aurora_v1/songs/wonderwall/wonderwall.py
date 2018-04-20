# string order: EADGBe
chords = dict([
('8th' , '690'),
('16th', '345'),
('half', '2760'),
('Em7' , 'E0wA2rD2gG0wB3be3p'),
('Em71', 'E0wA2rDxxGxxBxxexx'),
('Gp0' , 'ExxAxxDxxG0wB3re3g'),
('Gp1' , 'E0wA2rDxxGxxBxxexx'),
('Gp2' , 'ExxAxxD0wG0wB3re3g'),
('Gp3' , 'E3rA2gDxxGxxBxxexx'),
('Gp4' , 'E3rA2gD0wG0wB3be3p'),
('Gp5' , 'E2rA0wDxxGxxBxxexx'),
('Dp0' , 'ExxAxxD0wG2rBxxexx'),
('Dp1' , 'ExxAxxDxxG2rB3ge3b'),
('Dp2' , 'ExxAxxD0wG2rB3ge3b'),
('Dp3' , 'ExxAxxD0wG0wBxxexx'),
('Dp4' , 'ExxA0wD2rG2gB3be3p'),
('Dp5' , 'ExxAxxDxxG0wB3re3g'),
('Ap1' , 'ExxA0wD2rG0wBxxexx'),
('Ap2' , 'ExxA0wD2rG2gBxxexx'),
('Ap3' , 'ExxA0wD0wG0wBxxexx'),
('Ap4' , 'ExxA0wD2rG2gB3be3p'),
('Ap5' , 'ExxAxxDxxG2rB3ge3b'),
('Ap6' , 'ExxAxxDxxG0wB3re0w'),
('Cp1' , 'ExxA3rD2gG0wB3be3p'),
('Cp2' , 'ExxA3rD2gGxxBxxexx'),
('Cp3' , 'ExxAxxD0rG2gB3be3p'),
('rest', 'ExxAxxDxxGxxBxxexx')
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

g.write('1015')
g.write('\n')

for line in f.readlines():
    line = " ".join(line.split()).split()
    for chord in line:
        tab = chords[chord]
        g.write(tab)
        g.write('\n')

f.close()
g.close()
