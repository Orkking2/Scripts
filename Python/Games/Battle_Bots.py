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
        self.effective_health = self.effective_health - opponent_attack
    def defend (self):
        self.effective_health = self.effective_health + self.armour*dice()

def handicap_questions ():
    handicap_switch = input("Would you like a handicap? ")
    handicap_switch.lower()
    if handicap_switch == "yes":
        handicap = int(input("How extreme should your handicap be? (1-100) ")) % (100+1)
        return(handicap)
    else:
        handicap = 0
        return(handicap)

def initialization ():
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
        winner = False
    elif bot.health <= 0:
        life = False
        winner = True
    else:
        life = True

def bot_action (level):
    if level == 0:
        pass
    elif level == 1:
        if action_roll():
            human.takeDamage(bot.attack)
        else:
            pass
    elif level == 2:
        if action_roll():
            human.takeDamage(bot.attack)
        elif action_roll():
            bot.defend()
        else:
            pass
    elif level == 3:
        for i in range(dice()):
            if action_roll():
                human.takeDamage(bot.attack)
            elif action_roll():
                bot.defend()
            else:
                pass
    elif level == 4:
        for i in range(dice()):
            if action_roll():
                human.takeDamage(bot.attack)
            else:
                bot.defend()
    elif level == 5:
        for i in range(100**dice()):
            if action_roll():
                human.takeDamage(bot.attack)
            else:
                bot.defend()

def human_action():
    action = input("Would like to attack, defend, or do nothing? (a/d/n) ")
    action.lower()
    if action == 'a':
        bot.takeDamage(human.attack)
    elif action == 'd':
        human.defend
    else:
        pass

def game ():
    for i in range(10):
        print('\n')
    initialization()
    while life:
        bot_action()
        check_life()
        human_action()
        check_life()
    if winner:
        print("Congratulations on beating a level " + bot_handicap + " bot!")
    else:
        print("You lost this time but there is always tomorrow after today, try your luck again!")
    play_again = input("\n"+ "Would you like to play again? (y/n) ")
    play_again.lower()
    if play_again == 'y':
        game()
    else:
        print("Oh alright then, have a good day now, y'hear!")

game()