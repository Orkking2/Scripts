life = True
class player:
    def __init__(self, handicap, health, attack):
       self.handicap = handicap
       self.health = health + 10*handicap
       self.attack = attack + handicap
    def ai (self, level):
        pass

def handicap_questions ():
    handicap_switch = input("Would you like a handicap? ")
    handicap_switch.lower()
    if handicap_switch == "yes":
        handicap = int(input("How extreme should your handicap be? (1-100) ")) % (100+1)
        return(handicap)
    else:
        handicap = 0
        return(handicap)

def init ():
    handicap = handicap_questions()
    human = player(handicap, 100, 5)
    ai_level = int(input("What level would you like your opponent to be? (1-5) ")) % 6
    bot = player(ai_level,100,5)
    return(handicap,human,ai_level,bot)


def ai_bias (level,opponent_hp,opponent_attack):
    if level == 0:
        return()
    elif level == 1:
        pass
    elif level == 2:
        pass
    elif level == 3:
        pass
    elif level == 4:
        pass
    elif level == 5:
        pass

def game ():
    handicap, human, ai_level, bot = init()
    while life:
        return()