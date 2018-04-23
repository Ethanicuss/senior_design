# string order: EADGBe
chords = dict([
('32nd', '220'),
('32nd.', '328'),
('16th', '436'),
('16th.', '654'),
('16th.+16th', '1090'),
('triplet','290'),
('8th' , '870'),
('8th+32','1088'),
('8th+half','4350'),
('8th.', '1306'),
('8th.+8th', '2176'),
('8th.+quarter', '3046'),
('quarter','1740'),
('quarter.','2610'),
('half', '3480'),
('half.','5220'),
('whole','6960'),
('2whole','13920'),

('Dp1',  'ExxA5rDxxGxxB3gexx'),
('Dp2',  'ExxAxxD4rGxxBxxexx'),
('Dp3',  'ExxAxxDxxG2rBxxexx'),
('Dp4',  'ExxAxxDxxGxxB3rexx'),
('Dp5',  'ExxA4rDxxGxxBxxexx'),
('Dp6',  'ExxA2rDxxGxxBxxexx'),
('Dp7',  'E5rAxxDxxGxxBxxexx'),
('Dp8',  'E4rAxxDxxGxxBxxexx'),
('Dp9',  'ExxA4rDxxGxxB3gexx'),
('Dp10', 'ExxA5rDxxGxxBxxexx'),
('Dp11', 'ExxAxxDxxGxxB5rexx'),

('Fp1',  'E2rAxxDxxGxxB2gexx'),
('Fp2',  'ExxA4rDxxGxxBxxexx'),
('Fp3',  'ExxAxxD4rGxxBxxexx'),
('Fp4',  'ExxAxxDxxG3rBxxexx'),
('Fp5',  'ExxAxxD2rGxxBxxexx'),
('Fp6',  'ExxA5rDxxGxxBxxexx'),
('Fp7',  'ExxA2rDxxGxxBxxexx'),
('Fp8',  'E2rAxxDxxGxxBxxexx'),
('Fp9',  'ExxA9rDBgGBbBApexx'),
('Fp10', 'ExxAxxDBrGBgBAbe9p'),
('Fp11', 'ExxAxxD0wG0wB0wexx'),
('Fp11', 'ExxAxxDxxG2rB1ge0w'),
('Fp12', 'ExxAxxD0wG0wB0we0w'),
('Fp13', 'ExxA8rDAgGAbBApexx'),
('Fp14', 'ExxAxxDxxG0wB0we0w'),

('Ep1',  'ExxA5rD4gGxxBxxexx'),
('Ep2',  'ExxA7rD6gGxxBxxexx'),
('Ep3',  'ExxA7rD9gG9bB9pexx'),
('Ep4',  'ExxA7rD9gG8bB9pexx'),
('Ep5',  'ExxA7rD9gGxxBxxexx'),
('Ep6',  'ExxAxxDxxG7rB0wexx'),
('Ep7',  'ExxA7rDxxGxxBxxexx'),
('Ep8',  'ExxA7rD9gG9bB9peAp'),

('Cp1',  'ExxA9rD9gGxxBxxexx'),
('Cp2',  'ExxABrDBgGxxBxxexx'),
('Cp3',  'ExxAxxDxxG9rB9gexx'),
('Cp4',  'ExxABrDBgG9bB9pexx'),
('Cp5',  'ExxA9rDxxGxxBxxexx'),
('Cp6',  'ExxABrDxxGxxBxxexx'),
('Cp7',  'ExxAxxD7rG6gB5be0w'),
('Cp8',  'ExxAxxD5rG5gB5be0w'),

('Ap1',  'ExxA7rD7gG6bB5pexx'),
('Ap2',  'ExxA6rD6gG4bB4pexx'),
('Ap3',  'ExxAxxDxxGxxBxxe5r'),
('Ap4',  'ExxAxxDxxGxxBxxe7r'),
('Ap5',  'ExxAxxDxxG6rB5gexx'),
('Ap6',  'ExxAxxDxxGxxB5rexx'),
('Ap7',  'ExxAxxDxxG6rBxxexx'),
('Ap8',  'ExxAxxDxxG2rB0we0w'),
('Ap9',  'ExxAxxDxxG6rB5ge0w'),
('Ap10', 'ExxAxxDxxG5rB5ge0w'),
('Ap11', 'ExxAxxDxxGxxB1re0w'),

('Bp1',  'E7rA9gD9bG8pB7pexx'),
('Bp2',  'ExxAxxDxxG8rB7gexx'),
('Bp3',  'ExxA9rD9gGxxBxxexx'),
('Bp4',  'ExxAxxDxxG8rBxxexx'),
('Bp5',  'ExxAxxDxxG9rBxxexx'),
('Bp6',  'ExxA9rDxxGxxBxxexx'),
('Bp7',  'ExxAxxD0wGBrBCgeBb'),
('Bp8',  'ExxAxxDxxGxxB9rexx'),
('Bp9',  'ExxAxxDxxGxxB7rexx'),
('Bp10', 'ExxAxxD9rG8gBxxexx'),
('Bp11', 'E7rAxxDxxGxxBxxexx'),
('Bp12', 'ExxAxxDxxGxxBxxe9r'),
('Bp13', 'ExxAxxDxxGxxB7re7g'),
('Bp14', 'ExxAxxD9rGxxBxxexx'),
('Bp15', 'ExxAxxDxxG4rB5ge0w'),
('Bp16', 'ExxAxxDxxG4rB3ge0w'),

('Gp1',  'ExxA6rD6gG4bB4pexx'),
('Gp2',  'ExxA7rD9gG9bB9peAp'),

('Rp1',  'ExxAxxDxxGxxBxxe0w'),
('Rp2',  'ExxAxxDxxGxxB1rexx'),
('Rp3',  'ExxAxxDxxG2rBxxexx'),
('Rp4',  'ExxAxxDxxGxxB0we3r'),
('Rp5',  'ExxAxxDxxG4rB3gexx'),
('Rp6',  'ExxAxxDxxG2rB0wexx'),
('Rp7',  'ExxAxxDxxGxxB1re0w'),
('Rp8',  'ExxAxxDxxG2rB1gexx'),
('Rp9',  'ExxAxxDxxGxxB1rexx'),
('Rp10', 'ExxAxxDxxGxxB3rexx'),
('Rp11', 'ExxAxxDxxG2rBxxexx'),
('Rp12', 'ExxAxxDxxGxxB8rexx'),
('Rp13', 'ExxAxxDxxGxxB5rexx'),
('Rp14', 'ExxAxxDxxG5rBxxexx'),
('Rp15', 'ExxAxxD5rG4gB3bexx'),
('Rp16', 'ExxAxxD3rG2gB0wexx'),
('Rp17', 'ExxAxxD3rG2gB1be0w'),
('Rp18', 'ExxAxxD5rG4gB0wexx'),
('Rp19', 'ExxAxxDxxGxxB0wexx'),
('Rp20', 'ExxAxxD3rGxxBxxexx'),
('Rp21', 'ExxAxxDxxG7rBxxexx'),
('Rp22', 'ExxAxxD7rGxxBxxexx'),

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
g = open("bridge.txt", "w")

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
