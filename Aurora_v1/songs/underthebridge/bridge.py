# string order: EADGBe
chords = dict([
('32nd', ''),
('16th', ''),
('16th.', ''),
('16th.+16th', ''),
('triplet',''),
('8th' , ''),
('8th+32',''),
('8th.', ''),
('8th+half',''),
('quarter',''),
('quarter.',''),
('half', ''),
('half.',''),
('whole',''),
('2whole',''),

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

('Ep1',  'ExxA5_D4_GxxBxxexx'),
('Ep2',  'ExxA7_D6_GxxBxxexx'),
('Ep3',  'ExxA7_D9_G9_B9_exx'),
('Ep4',  'ExxA7_D9_G8_B9_exx'),
('Ep5',  'ExxA7_D9_GxxBxxexx'),
('Ep6',  'ExxAxxDxxG7_B0wexx'),
('Ep7',  'ExxA7_DxxGxxBxxexx'),

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

('Gp1',  'ExxA6_D6_G4_B4_exx'),

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
