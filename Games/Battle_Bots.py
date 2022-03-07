from random import *

def dice ():
    return(randint(1,6))

class player:
    def __init__(self, handicap):
       self.handicap = handicap
       self.health = 100 + 10*handicap*dice()
       self.effective_health = self.health
       self.attack = 25 + 5*handicap*dice()
       self.armour = 50 + handicap*dice()
    def takeDamage (self, opponent_attack):
        self.health = self.health - opponent_attack
    def defend (self):
        self.effective_health = self.health + self.armour*dice()

def handicap_questions ():
    handicap_switch = input("Would you like a handicap? ")
    handicap_switch.lower()
    if handicap_switch == "yes":
        handicap = int(input("How extreme should your handicap be? (1-100) ")) % (100+1)
        return(handicap)
    else:
        handicap = 0
        return(handicap)

#def initialization ():
human_handicap = handicap_questions()
human = player(human_handicap)
bot_handicap = int(input("What level would you like your opponent to be? (1-5) ")) % 6
bot = player(bot_handicap)
check_life()

def action_roll ():
    if dice() > 3:
        return(True)
    else:
        return(False)

def check_life ():
    if human.health <= 0:
        life = False
    elif bot.health <= 0:
        life = False
    else:
        pass

def ai_bias (level):
    if level == 0:
        pass
    elif level == 1:
        if action_roll():
            human.takeDamage(bot.attack)
        else:
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
    initialization()
    while life:
        return()