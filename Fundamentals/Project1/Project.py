import os
import random
import datetime
import time
import datetime
def display(): #This function will display the grid everytime
    now = datetime.datetime.now()
    print("\n \t\t\t\t{}".format(now.strftime("%Y-%B-%d %A %H:%M:%S")))
    print("\n  "+str(0)+"   "+str(1)+"   "+str(2)+"   "+str(3)+"   "+str(4)+"   "+str(5)+"   "+str(6)+"   ")
    print()  #Grid will be printed
    for i in range (6):           
            print('| '+a[i][0]+' | '+a[i][1]+' | '+a[i][2]+' | '+a[i][3]+' | '+a[i][4]+' | '+a[i][5]+' | '+a[i][6]+' |')
def tossplayers(p1,p2): #It will check the toss between two players
    rand=random.randint(1,2)
    toss=input("TOSS\nChoose '1' or '2' : ")
    while not (toss=='1' or toss=='2'):
        toss=input("Enter any number Valid Number Player 1  = ")
    os.system('cls')
    display()
    toss=int(toss)
    if(rand==toss): #COndition to check the toss
        print("{} is starting first".format(p1))
        return True
    else:
        print("{} is starting first".format(p2)) 
        return False
def toss(): #it will check the toss with computer
    rand=random.randint(1,2)
    toss=input("TOSS\nChoose '1' or '2' : ")
    while not (toss=='1' or toss=='2'):
        toss=input("Enter any number Valid Number Player 1  = ")
    os.system('cls')
    display()
    toss=int(toss)
    if(rand==toss): #check the condition of toss
        print("Congratulations! You are starting first")
        return True
    else:
        print("Computer is starting first")
        time.sleep(2)      
        return False
def fillslot(n,XO): #function to add your sign in the specific slot
    global a
    if n>=0 and n<=6:
        for i in range(5,-1,-1):
            if a[i][n]=="_": #condition to check whether it is already filled or not
                a[i][n]=XO
                os.system('cls')
                display()
                return True
        else:
            return False
def iswin(xo): #function to check the winner
    for i in range(7): #condition for vertical 4 pairs
        count=0
        for j in range(6):
            if a[j][i]==xo:
                count+=1
            if count==4:
                return True
                break
            if a[j][i]!=xo:
                count=0 
    for i in range(0,6): #condition to check horizontal 4 pairs
        count=0
        for j in range(0,7):
            if a[i][j]==xo:
                count+=1
            if count==4:
                return True
                break
            if a[i][j]!=xo:
                count=0
    for i in range(5,3,-1): #condition to check diagonal from left to right
        if a[i][0]==a[i-1][1]==a[i-2][2]==a[i-3][3]==xo:
            return True
            break
        if a[i][1]==a[i-1][2]==a[i-2][3]==a[i-3][4]==xo:
            return True
            break
        if a[i][2]==a[i-1][3]==a[i-2][4]==a[i-3][5]==xo:
            return True
            break
        if a[i][3]==a[i-1][4]==a[i-2][5]==a[i-3][6]==xo:
            return True
            break
    for i in range(5,3,-1): #condition to check diagonal pair from right to left
        if a[i][3]==a[i-1][2]==a[i-2][1]==a[i-3][0]==xo:
            return True
            break
        if a[i][4]==a[i-1][3]==a[i-2][2]==a[i-3][1]==xo:
            return True
            break
        if a[i][5]==a[i-1][4]==a[i-2][3]==a[i-3][2]==xo:
            return True
            break
        if a[i][6]==a[i-1][5]==a[i-2][4]==a[i-3][3]==xo:
            return True
            break
    return False
def Ai(x): #function to check possible conditions for Computer
    for i in range(7): #vertical conditon for making pair of 4
        count=0
        for j in range(6):
            if a[j][i]==x:
                count+=1
            if a[j][i]!=x:
                count=0
            if count==3:
                if a[j-3][i]=="O":
                    break           
                if not fillslot(i,x):
                    continue
                else:
                    return True
    for i in range(0,6): #Condition to make pair of 4 horizontally
        count=0
        for j in range(0,7):
            if a[i][j]==x:
                count+=1
            if a[i][j]!=x:
                count=0
            if count==3:
                if 0<=j<=5 and i<=4: #condition for top 5 rows and first 6 columns
                    if a[i][j+1]=="O":
                        continue
                    elif a[i+1][j+1]=="O" or a[i+1][j+1]==x:
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i<=4: #condition for top 5 rows and last 6 columns
                    if a[i][j-3]=="O":
                        continue
                    elif a[i+1][j-3]=="O" or a[i+1][j-3]==x:
                        if not fillslot(j-3,x):
                            continue
                        else:
                            return True
                if 0<=j<=5 and i==5: #condition for last row and first 6 columns
                    if a[i][j+1]=="O":
                        print("")
                    else:
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i==5: #condition for last row and last 6 columns
                    if a[i][j-3]=="O":
                        continue
                    else:
                        if not fillslot(j-3,x):
                            continue
                        else:
                            return True
    for i in range(5,3,-1): #Condition for diagonal from left to right to make pair of 4
        if a[i][0]==a[i-1][1]==a[i-2][2]==x and a[i-2][3]!="_" and a[i-3][3]=="_":
            if not fillslot(3,x):
                continue
            else:
                return True
                break
        if a[i][1]==a[i-1][2]==a[i-2][3]==x and a[i-2][4]!="_" and a[i-3][4]=="_":
            if not fillslot(4,x):
                continue
            else:
                return True
                break
        if a[i][2]==a[i-1][3]==a[i-2][4]==x and a[i-2][5]!="_" and a[i-3][5]=="_":
            if not fillslot(5,x):
                continue
            else:
                return True
                break
        if a[i][3]==a[i-1][4]==a[i-2][5]==x and a[i-2][6]!="_" and a[i-3][6]=="_":
            if not fillslot(6,x):
                continue
            else:
                return True
                break
    for i in range(5,3,-1): #Condition for diagonal from right to left to make pair of 4
        if a[i][3]==a[i-1][2]==a[i-2][1]==x and a[i-2][0]!="_" and a[i-3][0]=="_":
            if not fillslot(0,x):
                continue
            else:
                return True
                break
        if a[i][4]==a[i-1][3]==a[i-2][2]==x and a[i-2][1]!="_" and a[i-3][1]=="_":
            if not fillslot(1,x):
                continue
            else:
                return True
                break
        if a[i][5]==a[i-1][4]==a[i-2][3]==x and a[i-2][2]!="_" and a[i-3][2]=="_":
            if not fillslot(2,x):
                continue
            else:
                return True
                break
        if a[i][6]==a[i-1][5]==a[i-2][4]==x and a[i-2][3]!="_" and a[i-3][3]=="_":
            if not fillslot(3,x):
                continue
            else:
                return True
                break
    for i in range(7): #Condition for blocking the player to make the pair of 3 vertically
            count=0
            for j in range(6):
                if a[j][i]=="O":
                    count+=1
                if a[j][i]!="O":
                    count=0
                if count==3:
                    if a[j-3][i]=="X":
                        break           
                    if not fillslot(i,x):
                        continue
                    else:
                        return True
    for i in range(0,6): # Condition for blocking player from completing the pair of 4 horizontally
        count=0
        for j in range(0,7):
            if a[i][j]=="O":
                count+=1
            if a[i][j]!="O":
                count=0
            if count==3:
                print("Counted 3")
                if 0<=j<=5 and i<=4:
                    if a[i][j+1]==x:
                        continue
                    elif a[i+1][j+1]==x or a[i+1][j+1]=="O":
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i<=4:
                    if a[i][j-3]==x:
                        continue
                    elif a[i+1][j-3]==x or a[i+1][j-3]=="O":
                        if not fillslot(j-3,x):
                            continue
                        else:
                            return True
                if 0<=j<=5 and i==5:
                    if a[i][j+1]==x:
                        print("")
                    else:
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i==5:
                    if a[i][j-3]==x:
                        continue
                    else:
                        if not fillslot(j-3,x):
                            continue
                        else:
                            return True
    for i in range(0,6): # condition for blocking the= player to make condition pair of 3 horizontal
        count=0
        for j in range(0,7):
            if a[i][j]=="O":
                count+=1
            if a[i][j]!="O":
                count=0
            if count==2:
                if 0<=j<=4 and i<=4:
                    if a[i][j+1]==x:
                        continue
                    elif a[i+1][j+1]==x or a[i+1][j+1]=="O":
                        if a[i][j+2]=="O":
                            if not fillslot(j+1,x):
                                continue
                            else:
                                return True
                if 2<=j<=6 and i<=4:
                    if a[i][j-2]==x:
                        continue
                    elif a[i+1][j-2]==x or a[i+1][j-2]=="O":
                        if a[i][j-3]=="O":
                            if not fillslot(j-2,x):
                                continue
                            else:
                                return True
                if 0<=j<=4 and i==5:
                    if a[i][j+1]==x:
                        print("")
                    elif a[i][j+2]=="O":
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i==5:
                    if a[i][j-2]==x:
                        continue
                    elif a[i][j-3]=="O":
                        if not fillslot(j-2,x):
                            continue
                        else:
                            return True
    for i in range(5,3,-1): #Condition for bloking the player frommaking the pair of 4 diagonally from left ot right
        if a[i][0]==a[i-1][1]==a[i-2][2]=="O" and a[i-2][3]!="_" and a[i-3][3]=="_":
            if not fillslot(3,x):
                continue
            else:
                return True
                break
        if a[i][1]==a[i-1][2]==a[i-2][3]=="O" and a[i-2][4]!="_" and a[i-3][4]=="_":
            if not fillslot(4,x):
                continue
            else:
                return True
                break
        if a[i][2]==a[i-1][3]==a[i-2][4]=="O" and a[i-2][5]!="_" and a[i-3][5]=="_":
            if not fillslot(5,x):
                continue
            else:
                return True
                break
        if a[i][3]==a[i-1][4]==a[i-2][5]=="O" and a[i-2][6]!="_" and a[i-3][6]=="_":
            if not fillslot(6,x):
                continue
            else:
                return True
                break
    for i in range(5,3,-1): #Condition for bloking the player frommaking the pair of 4 diagonally from right to left
        if a[i][3]==a[i-1][2]==a[i-2][1]=="O" and a[i-2][0]!="_" and a[i-3][0]=="_":
            if not fillslot(0,x):
                continue
            else:
                return True
                break
        if a[i][4]==a[i-1][3]==a[i-2][2]=="O" and a[i-2][1]!="_" and a[i-3][1]=="_":
            if not fillslot(1,x):
                continue
            else:
                return True
                break
        if a[i][5]==a[i-1][4]==a[i-2][3]=="O" and a[i-2][2]!="_" and a[i-3][2]=="_":
            if not fillslot(2,x):
                continue
            else:
                return True
                break
        if a[i][6]==a[i-1][5]==a[i-2][4]=="O" and a[i-2][3]!="_" and a[i-3][3]=="_":
            if not fillslot(3,x):
                continue
            else:
                return True
                break
    for i in range(0,6): #condition for blocking the pair of horizontally
        count=0
        for j in range(0,7):
            if a[i][j]=="O":
                count+=1
            if a[i][j]!="O":
                count=0
            if count==2:
                print("Counted 2")
                if 0<=j<=5 and i<=4:
                    if a[i][j+1]==x or a[i][j+1]=="O" :
                        continue
                    elif a[i+1][j+1]==x or a[i+1][j+1]=="O":
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i<=4:
                    if a[i][j-2]==x or a[i][j-2]=="O":
                        continue
                    elif a[i+1][j-2]==x or a[i+1][j-2]=="O":
                        if not fillslot(j-2,x):
                            continue
                        else:
                            return True
                if 0<=j<=5 and i==5:
                    if a[i][j+1]==x or a[i][j+1]=="O":
                        print("")
                    else:
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i==5:
                    if a[i][j-2]==x or a[i][j-2]=="O":
                        continue
                    else:
                        if not fillslot(j-2,x):
                            continue
                        else:
                            return True
    for i in range(5,3,-1): #Condition for blocking the player from making the pair of 3 diagonally
        if a[i][0]==a[i-1][1]=="O" and a[i-1][2]!="_" and a[i-2][2]=="_":
            if not fillslot(2,x):
                continue
            else:
                return True
                break
        if a[i][1]==a[i-1][2]=="O" and a[i-1][3]!="_" and a[i-2][3]=="_":
            if not fillslot(3,x):
                continue
            else:
                return True
                break
        if a[i][2]==a[i-1][3]=="O" and a[i-1][4]!="_" and a[i-2][4]=="_":
            if not fillslot(4,x):
                continue
            else:
                return True
                break
        if a[i][3]==a[i-1][4]=="O" and a[i-1][5]!="_" and a[i-2][5]=="_":
            if not fillslot(5,x):
                continue
            else:
                return True
                break
        for i in range(5,3,-1):
            if a[i][3]==a[i-1][2]=="O" and a[i-1][1]!="_" and a[i-2][1]=="_":
                if not fillslot(1,x):
                    continue
                else:
                    return True
                    break
            if a[i][4]==a[i-1][3]=="O" and a[i-1][2]!="_" and a[i-2][2]=="_":
                if not fillslot(2,x):
                    continue
                else:
                    return True
                    break
            if a[i][5]==a[i-1][4]=="O" and a[i-1][3]!="_" and a[i-2][3]=="_":
                if not fillslot(3,x):
                    continue
                else:
                    return True
                    break
            if a[i][6]==a[i-1][5]=="O" and a[i-1][4]!="_" and a[i-2][4]=="_":
                if not fillslot(4,x):
                    continue
                else:
                    return True
                    break
    for i in range(7): #Condition for making vertical 3
        count=0
        for j in range(6):
            if a[j][i]==x:
                count+=1
            if a[j][i]!=x:
                count=0
            if count==2:
                if a[j-2][i]=="O":
                    break           
                if not fillslot(i,x):
                    continue
                else:
                    return True
    for i in range(0,6): #Condition for blocking the player from making the pair of 3 Horizontal 
        count=0
        for j in range(0,7):
            if a[i][j]==x:
                count+=1
            if a[i][j]!=x:
                count=0
            if count==2:
                if 0<=j<=5 and i<=4:
                    if a[i][j+1]=="O" or a[i][j+1]==x :
                        continue
                    elif a[i+1][j+1]=="O" or a[i+1][j+1]==x:
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i<=4:
                    if a[i][j-2]=="O" or a[i][j-2]==x:
                        continue
                    elif a[i+1][j-2]=="O" or a[i+1][j-2]==x:
                        if not fillslot(j-2,x):
                            continue
                        else:
                            return True
                if 0<=j<=5 and i==5:
                    if a[i][j+1]=="O" or a[i][j+1]==x:
                        print("")
                    else:
                        if not fillslot(j+1,x):
                            continue
                        else:
                            return True
                if 1<=j<=6 and i==5:
                    if a[i][j-2]=="O" or a[i][j-2]==x:
                        continue
                    else:
                        if not fillslot(j-2,x):
                            continue
                        else:
                            return True
    for i in range(5,3,-1): #Condition for making the pair of 3 diagonally
        if a[i][0]==a[i-1][1]==x and a[i-1][2]!="_" and a[i-2][2]=="_":
            if not fillslot(2,x):
                continue
            else:
                return True
                break
        if a[i][1]==a[i-1][2]==x and a[i-1][3]!="_" and a[i-2][3]=="_":
            if not fillslot(3,x):
                continue
            else:
                return True
                break
        if a[i][2]==a[i-1][3]==x and a[i-1][4]!="_" and a[i-2][4]=="_":
            if not fillslot(4,x):
                continue
            else:
                return True
                break
        if a[i][3]==a[i-1][4]==x and a[i-1][5]!="_" and a[i-2][5]=="_":
            if not fillslot(5,x):
                continue
            else:
                return True
                break
        for i in range(5,3,-1):
            if a[i][3]==a[i-1][2]==x and a[i-1][1]!="_" and a[i-2][1]=="_":
                if not fillslot(1,x):
                    continue
                else:
                    return True
                    break
            if a[i][4]==a[i-1][3]==x and a[i-1][2]!="_" and a[i-2][2]=="_":
                if not fillslot(2,x):
                    continue
                else:
                    return True
                    break
            if a[i][5]==a[i-1][4]==x and a[i-1][3]!="_" and a[i-2][3]=="_":
                if not fillslot(3,x):
                    continue
                else:
                    return True
                    break
            if a[i][6]==a[i-1][5]==x and a[i-1][4]!="_" and a[i-2][4]=="_":
                if not fillslot(4,x):
                    continue
                else:
                    return True
                    break   
    return False            
def filewrite(playerscore): #Function to secure scores in File
    global player
    file=open("File.txt","a")
    now = datetime.datetime.now() #Using date time module
    file.write("{}\t{}\t{}\n".format(player,playerscore,now.strftime("%Y-%M-%D %H:%M:%S")))
    file.close
def computer(): #Function to run the Computer turn
    global playerscore
    sign='X'
    if not Ai(sign): #Condition to check whether Ai work or not
        value=random.randint(0,6) #Otherwise it will select randomly
        while not fillslot(value,sign):
            value=random.randint(0,6)
    if iswin(sign): #Check the condition for winning
        filewrite(playerscore)     
        print("\n-------------------------")
        print("Oops! Game Over! Computer Wins")
        print("-------------------------")
        print("Your Score is : {}\n".format(playerscore))
        print("-------------------------")
        Restart=input("\nIf you want to Play again press 'R' : ")
        if Restart=="R" or "r":
            main()
def playerturn(p,s): #Function will run the player turn
    global Option
    global playerscore
    playerscore+=10
    value=input("\n{} Choose bewteen '0' to '6' : ".format(p)) #Takes input from the user
    while not value.isnumeric():
        value=input("Enter any number Valid Number {}  = ".format(p))
    value=int(value)
    while not fillslot(value,s):
        print("Entered any valid Value")
        value=input("Please! Choose between '0' to '6' {} : ".format(p))
        while not value.isnumeric():
            value=input("Enter any number Valid Number {}  = ".format(p))
        value=int(value)
    if iswin(s): #CHeck the condition for winner
        playerscore=1000
        if Option=="p" or Option=="P":
            filewrite(playerscore)
        print("\n-------------------------")
        print("Congratulations! YOU WIN {}!".format(p))
        print("-------------------------")
        if Option=="p" or Option=="P":
            print("Your Score is : {}\n".format(playerscore))
            print("-------------------------")
        Restart=input("\nIf you want to Play again press 'R' : ")
        if Restart=="R" or "r":
            main()

def main():
    while True:    #Main Fucntion starts Here!
        global a
        a=[["_","_","_","_","_","_","_"],
["_","_","_","_","_","_","_"],
["_","_","_","_","_","_","_"],
["_","_","_","_","_","_","_"],
["_","_","_","_","_","_","_"],
["_","_","_","_","_","_","_"]]
        global playerscore
        global player
        playerscore=0
        compscore=0
        os.system("cls")
        display()
        count=0
        restarting=0
        global Option
        Option=input("\nIf you want to check High score press 'H':\nIf you want to Play with computer press 'P'\nIf you want to play against another player press 'S'\nIf you want to read instrction press 'I' :  ") #asks user for what does they want to do
        if Option=="I" or Option=="i":
            os.system("cls")
            file=open("instructions.txt")
            file=file.read()
            print(file)
            Restart=input("\nIf you want to go to main menu, press 'R' : ")
            if Restart=="R" or "r":
                main()
        if Option=="S" or Option=="s": #Condition for 2 player mode
            player1sign="O" #sign pf player 1
            player2sign="X" #sign of player 2
            global player1
            global player2
            player1=input("Please Enter Your First name Player 1 : ") #Asks for name of player 1
            while not player1.isalpha():
                player1=input("Please Enter Your First  name only (using only Alphabets without spaces) : ")
            player2=input("Please Enter Your First name player 2 : ") #asks for name of player 2
            while not player2.isalpha():
                player2=input("Please Enter Your First  name only (using only Alphabets without spaces) : ")
            if(tossplayers(player1,player2)):
                while True:
                    playerturn(player1,player1sign)
                    playerturn(player2,player2sign)
                    count+=1
                    if count==21:
                        print("It is a Draw")
                        exit()
            else:
                while True:
                    playerturn(player2,player2sign)
                    playerturn(player1,player1sign)
                    count+=1
                    if count==21:
                        print("It is a Draw")
                        exit()
            
        if Option=="P" or Option=="p": #Condition for playing against computer
            playersign="O"
            player=input("Please Enter Your First name : ") #Asks user for his/her name
            while not player.isalpha():
                player=input("Please Enter Your First  name only (using only Alphabets without spaces) : ")
            if(toss()):
                while True:
                    playerturn(player,playersign)
                    computer()
                    count+=1
                    if count==21:
                        print("It is a Draw")
                        exit()
            else:
                while True:
                    computer()
                    playerturn(player,playersign)
                    count+=1
                    if count==21:
                        print("It is a Draw")
                        exit()
        if Option=="H" or Option=="h": #Condition for displaying high score 
            file=open("File.txt","r")
            line=[]
            line=file.readlines()
            score=[]
            diction={}
            diction1={}
            for i in line:
                if i.isspace():
                    continue
                scoree=i.split("\t")
                score=scoree[2]
                diction[scoree[0]]=scoree[1]
                diction1[scoree[2]]=scoree[1]
                
            pairs=list(diction.items())
            items = [[int(x.rstrip()), y] for (y, x) in pairs]
            items.sort(reverse=True)
            sliced=items[0:5]
            pairs=list(diction1.items())
            items1 = [[int(x.rstrip()), y] for (y, x) in pairs]
            items1.sort(reverse=True)
            sliced1=items1[0:5]  
            os.system("cls")
            print("-----------------------------------------------------------------------------------------")
            print("                                 TOP 5 HIGH SCORES")
            print("-----------------------------------------------------------------------------------------")
            print("  Player Name           :            High score         :               Time(Played at)")
            print("-----------------------------------------------------------------------------------------\n")
            for i in sliced:
                for j in sliced1:
                    print(" "+str(i[-1])+"     \t\t:\t\t"+str(i[0])+"\t\t:\t    " +str(j[-1]))
                    break
            Restart=input("\nIf you want to go to main menu, press 'R' : ")
            if Restart=="R" or "r":
                main()

main()


