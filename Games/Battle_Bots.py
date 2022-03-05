life = True
class player:
    def __init__(self, handicap, health, attack):
       self.handicap = handicap
       self.health = health + 10*handicap
       self.attack = attack + handicap
    def ai (self, level):
        ai_bias(level)

def handicap_questions ():
    handicap_switch = input("Would you like a handicap? ")
    handicap_switch.lower()
    if handicap_switch == "yes":
        handicap = int(input("How extreme should your handicap be? (1-100) ")) % (100+1)
        return(handicap)
    else:
        handicap = 0
        return(handicap)

handicap = handicap_questions()
you = player(handicap, 100, 5)


def ai_bias (level):
    pass

def game ():
    while life == True:
        pass