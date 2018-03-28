# string order: EADGBe
chords = dict([
('32nd', '109'),
('32nd.', '164'),
('16th', '218'),
('16th.', '327'),
('16th.+16th', '545'),
('triplet','145'),
('8th' , '435'),
('8th+32','544'),
('8th+half','2175'),
('8th.', '653'),
('8th.+8th', '1088'),
('8th.+quarter', '1523'),
('quarter','870'),
('quarter.','1305'),
('half', '1740'),
('half.','2610'),
('whole','3480'),
('2whole','6960'),

('Dp1',  'ExxA5_DxxGxxB3_exx'),
('Dp2',  'ExxAxxD4_GxxBxxexx'),
('Dp3',  'ExxAxxDxxG2_Bxxexx'),
('Dp4',  'ExxAxxDxxGxxB3_exx'),
('Dp5',  'ExxA4_DxxGxxBxxexx'),
('Dp6',  'ExxA2_DxxGxxBxxexx'),
('Dp7',  'E5_AxxDxxGxxBxxexx'),
('Dp8',  'E4_AxxDxxGxxBxxexx'),
('Dp9',  'ExxA4_DxxGxxB3_exx'),
('Dp10', 'ExxA5_DxxGxxBxxexx'),
('Dp11', 'ExxAxxDxxGxxB5_exx'),

('Fp1',  'E2_AxxDxxGxxB2_exx'),
('Fp2',  'ExxA4_DxxGxxBxxexx'),
('Fp3',  'ExxAxxD4_GxxBxxexx'),
('Fp4',  'ExxAxxDxxG3_Bxxexx'),
('Fp5',  'ExxAxxD2_GxxBxxexx'),
('Fp6',  'ExxA5_DxxGxxBxxexx'),
('Fp7',  'ExxA2_DxxGxxBxxexx'),
('Fp8',  'E2_AxxDxxGxxBxxexx'),
('Fp9',  'ExxA9_DB_GB_BA_exx'),
('Fp10', 'ExxAxxDB_GB_BA_e9_'),
('Fp11', 'ExxAxxD0wG0wB0wexx'),
('Fp11', 'ExxAxxDxxG2_B1_e0w'),
('Fp12', 'ExxAxxD0wG0wB0we0w'),
('Fp13', 'ExxA8_DA_GA_BA_eC_'),
('Fp14', 'ExxAxxDxxG0wB0we0w'),

('Ep1',  'ExxA5_D4_GxxBxxexx'),
('Ep2',  'ExxA7_D6_GxxBxxexx'),
('Ep3',  'ExxA7_D9_G9_B9_exx'),
('Ep4',  'ExxA7_D9_G8_B9_exx'),
('Ep5',  'ExxA7_D9_GxxBxxexx'),
('Ep6',  'ExxAxxDxxG7_B0wexx'),
('Ep7',  'ExxA7_DxxGxxBxxexx'),
('Ep8',  'ExxA7_D9_G9_B9_eA_'),

('Cp1',  'ExxA9_D9_GxxBxxexx'),
('Cp2',  'ExxAB_DB_GxxBxxexx'),
('Cp3',  'ExxAxxDxxG9_B9_exx'),
('Cp4',  'ExxAB_DB_G9_B9_exx'),
('Cp5',  'ExxA9_DxxGxxBxxexx'),
('Cp6',  'ExxAB_DxxGxxBxxexx'),
('Cp7',  'ExxAxxD7_G6_B5_e0w'),
('Cp8',  'ExxAxxD5_G5_B5_e0w'),

('Ap1',  'ExxA7_D7_G6_B5_exx'),
('Ap2',  'ExxA6_D6_G4_B4_exx'),
('Ap3',  'ExxAxxDxxGxxBxxe5_'),
('Ap4',  'ExxAxxDxxGxxBxxe7_'),
('Ap5',  'ExxAxxDxxG6_B5_exx'),
('Ap6',  'ExxAxxDxxGxxB5_exx'),
('Ap7',  'ExxAxxDxxG6_Bxxexx'),
('Ap8',  'ExxAxxDxxG2_B0we0w'),
('Ap9',  'ExxAxxDxxG6_B5_e0w'),
('Ap10', 'ExxAxxDxxG5_B5_e0w'),
('Ap11', 'ExxAxxDxxGxxB1_e0w'),

('Bp1',  'E7_A9_D9_G8_B7_exx'),
('Bp2',  'ExxAxxDxxG8_B7_exx'),
('Bp3',  'ExxA9_D9_GxxBxxexx'),
('Bp4',  'ExxAxxDxxG8_Bxxexx'),
('Bp5',  'ExxAxxDxxG9_Bxxexx'),
('Bp6',  'ExxA9_DxxGxxBxxexx'),
('Bp7',  'ExxAxxD0wGB_BC_eB_'),
('Bp8',  'ExxAxxDxxGxxB9_exx'),
('Bp9',  'ExxAxxDxxGxxB7_exx'),
('Bp10', 'ExxAxxD9_G8_Bxxexx'),
('Bp11', 'E7_AxxDxxGxxBxxexx'),
('Bp12', 'ExxAxxDxxGxxBxxe9_'),
('Bp13', 'ExxAxxDxxGxxB7_e7_'),
('Bp14', 'ExxAxxD9_GxxBxxexx'),
('Bp15', 'ExxAxxDxxG4_B5_e0w'),
('Bp16', 'ExxAxxDxxG4_B3_e0w'),

('Gp1',  'ExxA6_D6_G4_B4_exx'),
('Gp2',  'ExxA7_D9_G9_B9_eA_'),

('Rp1',  'ExxAxxDxxGxxBxxe0w'),
('Rp2',  'ExxAxxDxxGxxB1_exx'),
('Rp3',  'ExxAxxDxxG2_Bxxexx'),
('Rp4',  'ExxAxxDxxGxxB0we3_'),
('Rp5',  'ExxAxxDxxG4_B3_exx'),
('Rp6',  'ExxAxxDxxG2_B0wexx'),
('Rp7',  'ExxAxxDxxGxxB1_e0w'),
('Rp8',  'ExxAxxDxxG2_B1_exx'),
('Rp9',  'ExxAxxDxxGxxB1_exx'),
('Rp10', 'ExxAxxDxxGxxB3_exx'),
('Rp11', 'ExxAxxDxxG2_Bxxexx'),
('Rp12', 'ExxAxxDxxGxxB8_exx'),
('Rp13', 'ExxAxxDxxGxxB5_exx'),
('Rp14', 'ExxAxxDxxG5_Bxxexx'),
('Rp15', 'ExxAxxD5_G4_B3_exx'),
('Rp16', 'ExxAxxD3_G2_B0wexx'),
('Rp17', 'ExxAxxD3_G2_B1_e0w'),
('Rp18', 'ExxAxxD5_G4_B0wexx'),
('Rp19', 'ExxAxxDxxGxxB0wexx'),
('Rp20', 'ExxAxxD3_GxxBxxexx'),
('Rp21', 'ExxAxxDxxG7_Bxxexx'),
('Rp22', 'ExxAxxD7_GxxBxxexx'),

('rest', 'ExxAxxDxxGxxBxxexx')
])

fractions = dict([
('32nd', .03125),
('32nd.', .046875),
('16th', .0625),
('16th.', .09375),
('16th.+16th', .15625),
('triplet', .041666),
('8th' , .125),
('8th+32', .15625),
('8th+half', .625),
('8th.', .1875),
('8th.+quarter', .4375),
('quarter', .25),
('quarter.', .375),
('half', .5),
('half.', .75),
('whole', 1),
('2whole', 2)
])

f = open("chords.txt", "r+")
g = open("tabs.txt", "w")

g.write('1370')
g.write('\n')

lines = f.readlines()
for line in lines:
    l = " ".join(line.split()).split()
    for item in l:
        index = item.find('(')
        if index == -1:
            tab = chords[item]
            g.write(tab)
            g.write('\n')
        else:
            chord = item[:index]
            shift = item[index:]
            tab = chords[chord]
            g.write(tab)
            g.write(shift)
            g.write('\n')

f.close()
g.close()
