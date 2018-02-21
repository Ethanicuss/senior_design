# string order: EADGBe
chords = dict([
('8th' , '345'),
('16th', '172'),
('half', '1380'),
('Em7' , 'E0wA2_D2_G0wB3_e3_'),
('Em71', 'E0wA2_DxxGxxBxxexx'),
('Gp0' , 'ExxAxxDxxG0wB3_e3_'),
('Gp1' , 'E0wA2_DxxGxxBxxexx'),
('Gp2' , 'ExxAxxD0wG0wB3_e3_'),
('Gp3' , 'E3_A2_DxxGxxBxxexx'),
('Gp4' , 'E3_A2_D0wG0wB3_e3_'),
('Gp5' , 'E2_A0wDxxGxxBxxexx'),
('Dp0' , 'ExxAxxD0wG2rBxxexx'),
('Dp1' , 'ExxAxxDxxG2_B3_e3_'),
('Dp2' , 'ExxAxxD0wG2_B3_e3_'),
('Dp3' , 'ExxAxxD0wG0wBxxexx'),
('Dp4' , 'ExxA0wD2_G2_B3_e3_'),
('Dp5' , 'ExxAxxDxxG0wB3_e3_'),
('Ap1' , 'ExxA0wD2_G0wBxxexx'),
('Ap2' , 'ExxA0wD2_G2_Bxxexx'),
('Ap3' , 'ExxA0wD0wG0wBxxexx'),
('Ap4' , 'ExxA0wD2_G2_B3_e3_'),
('Ap5' , 'ExxAxxDxxG2_B3_e3_'),
('Ap6' , 'ExxAxxDxxG0wB3_e0w'),
('Cp1' , 'ExxA3_D2_G0wB3_e3_'),
('Cp2' , 'ExxA3_D2_GxxBxxexx'),
('Cp3' , 'ExxAxxD0_G2_B3_e3_'),
('rest', 'ExxAxxDxxGxxBxxexx')
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

linenum = 0

for line in f.readlines():
    linenum += 1
    measuresum = 0.0
    line = " ".join(line.split()).split()
    for chord in line:
        tab = chords[chord]
        g.write(tab)
        g.write('\n')
        if(chord == "16th"):
            measuresum += .0625
        if(chord == "8th"):
            measuresum += .125
        if(chord == "half"):
            measuresum += .5
    if(measuresum != 1):
        print(linenum)
        print(measuresum)

f.close()
g.close()
