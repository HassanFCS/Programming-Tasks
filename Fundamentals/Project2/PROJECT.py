import os,datetime
Info={}
file=open("Project.txt", "r")
data = file.readlines()
for line in data: 
    word = line.split(" ")
    Info[word[0]]=word[1]#This will save password against the name
file.close()
os.system("cls")
while True:#Opening of shop and the main while lopp
    print("**************************")
    print("* Welcome to Python Shop *")
    print("**************************")
    print()
    print('If you dont have an account then sign up\nIf you have one then Sign In')
    print()
    print("1: Sign Up")
    print("2: Sign In")   
    x=input("Select either 1 or 2 : ")
    if(x=="1" or x=="2"):
        if(x=="1"):#This is for sign Up
            os.system('cls')
            while True:
                print('Sign Up Menu')
                print()
                Username=input("Enter Username(No Spacing): ")
                if Username in Info:
                    os.system("cls")
                    print("User Already Exists Enter again")
                    continue
                else:
                    Password=input("Enter Password(No spacing): ")
                    Address=input("Enter Address: ")
                    print("Sign up Successfull.")
                    break
            file = open('Project.txt','a') 
            file.write(Username + " " + Password + " " + Address + "\n")
            file.close()
            y=input("Enter 1 to exit. Enter ny other key to return to menu:")
            if y=="1":
                exit() 
        if x=="2":#This will be for Sign In and we will declare all the values of variables as zero
            os.system("cls")
            pn=[]
            pp=[]
            Bill=0
            MSh=MTs=MJe=MDe=MJc=MSho=0
            WSh=WTs=WJe=WDe=WJc=WSho=0
            KSh=KTs=KJe=KDe=KJc=KSho=0
            Fty1=Fty2=Fty3=0
            checkout=True
            while(checkout):
                print('Login Menu\nKindly Enter Your Details')
                Name=input("Enter Username: ")               
                info={}
                file=open("Project.txt", "r")
                data = file.readlines()
                for line in data: 
                    word = line.split(" ")
                    Info[word[0]]=word[1]#To check the saved password against name
                file.close()
                if Name in Info:
                    Pass=input("Enter Password: ")
                    if(Info[Name]==Pass):
                        os.system('cls')
                        print("Welcome to the Python Wardrobe Shop")
                        while(checkout):
                            while(True):#This is the after menu (section corner)
                                print("1. Men Corner")
                                print("2. Women Corner")
                                print("3. Kids Corner")
                                print("4. Fragrances")
                                x=eval(input("Select (1-4) for respective corners or 5 for Checkout: "))
                                if(x>=1 and x<=5):
                                    break
                                else:
                                    os.system('cls')
                                    print('Kindly Select from (1-5)')
                                    continue
                            if(x==1):
                                os.system('cls')
                                print('Welcome to Men\'s Corner')
                                print()
                                print("1. Shirts\t1500")
                                print("2. T-Shirts\t1000")
                                print("3. Jeans\t2500")
                                print("4. Denim\t2000")
                                print("5. Jacket\t5000")
                                print("6. Shoes\t2500")
                                x=eval(input("Select (1-6) for respective items or press any other key to return to Corner menu :"))
                                os.system('cls')
                                if(x==1):
                                    MSh+=1
                                elif(x==2):
                                    MTs+=1
                                elif(x==3):
                                    MJe+=1
                                elif(x==4):
                                    MDe+=1
                                elif(x==5):
                                    MJc+=1
                                elif(x==6):
                                    MSho+=1                               
                            elif(x==2):
                                os.system('cls')
                                print('Welcome to Women\'s Corner')
                                print()
                                print("1. Shirts\t1500")
                                print("2. T-Shirts\t1000")
                                print("3. Jeans\t2500")
                                print("4. Denim\t2000")
                                print("5. Jacket\t5000")
                                print("6. Shoes\t2500")
                                x=eval(input("Select (1-6) for respective items or press any other key to return to Corner menu :"))
                                os.system('cls')
                                if(x==1):
                                    WSh+=1
                                elif(x==2):
                                    WTs+=1
                                elif(x==3):
                                    WJe+=1
                                elif(x==4):
                                    WDe+=1
                                elif(x==5):
                                    WJc+=1
                                elif(x==6):
                                    WSho+=1
                            elif(x==3):
                                os.system('cls')
                                print('Welcome to Kids Corner')
                                print()
                                print("1. Shirts\t1500")
                                print("2. TShirts\t1000")
                                print("3. Jeans\t2500")
                                print("4. Denim\t2000")
                                print("5. Jacket\t5000")
                                print("6. Shoes\t2500")
                                x=eval(input("Select (1-6) for respective items or press any other key to return to Corner menu :"))
                                os.system('cls')
                                if(x==1):
                                    KSh+=1
                                elif(x==2):
                                    KTs+=1
                                elif(x==3):
                                    KJe+=1
                                elif(x==4):
                                    KDe+=1
                                elif(x==5):
                                    KJc+=1
                                elif(x==6):
                                    KSho+=1
                            elif(x==4):
                                os.system('cls')
                                print('Welcome to Fragrnces Corner')
                                print()
                                print("1. Type1\t1500")
                                print("2. Type2\t2500")
                                print("3. Type3\t5500")
                                x=eval(input("Select (1-3) for respective items or press any other key to return to Corner menu :"))
                                os.system('cls')
                                if(x==1):
                                    Fty1+=1
                                elif(x==2):
                                    Fty2+=1
                                elif(x==3):
                                    Fty3+=1
                            elif(x==5):#Condition for checkout
                                nflag=True
                                while(nflag):
                                    ANo=""
                                    while(len(ANo)!=19):
                                        os.system('cls')
                                        print('Kindly Enter your Account No. for payement')
                                        print()
                                        ANo=input("Enter Account no.(format XXXX-XXXX-XXXX-XXXX): ")
                                        os.system("cls")
                                    if(ANo[4]!='-' or ANo[9]!='-' or ANo[14]!='-'):
                                        nflag=True
                                    else:
                                        count=0
                                        for j in range(len(ANo)):
                                            if(j!=4 or j!=9 or j!=14):
                                                if(ANo[j]>='0' and ANo[j]<='9'):
                                                    count+=1
                                            else:
                                                nflag=True
                                        if(count==16):
                                                nflag=False
                                #Here we will be calculating the whole bill                
                                Bill=(MSh*1500 + MTs*1000 + MJe*2500 + MDe*2000 + MJc*5000 + MSho*2500) + (WSh*1500 + WTs*1000 + WJe*2500 + WDe*2000 + WJc*5000 + WSho*2500) + (KSh*1500 + KTs*1000 + KJe*2500 + KDe*2000 + KJc*5000 + KSho*2500) + (Fty1*1500 + Fty2*2500 + Fty3*5500)
                                checkout=False
                                file= open('ProOrders.txt','w').close()
                                file1 = open('ProOrders.txt','a')
                                file1.write(Name + "\n")
                                file1.write(ANo + "\n")
                                file1.write(str(Bill) + "\n")
                                #Condtion to write the names o purchased items in the list
                                if(MSh>0):
                                    file1.write(str(MSh) + "   M-Shirts  " + str(1500*MSh)+"   "+str(1500)+'\n')
                                if(MTs>0):
                                    file1.write(str(MTs) + "   M-TShirts "+ str(1000*MTs)+"   "+str(1000)+'\n')
                                if(MJe>0):
                                    file1.write(str(MJe) + "   M-Jeans   "+ str(2500*MJe)+"   "+str(2500)+'\n')
                                if(MDe>0):
                                    file1.write(str(MDe) + "   M-Denim   "+ str(2000*MDe)+"   "+str(2000)+'\n')
                                if(MJc>0):
                                    file1.write(str(MJc) + "   M-Jacket  "+ str(5000*MJc)+"   "+str(5000)+'\n')
                                if(MSho>0):
                                    file1.write(str(MSho) + "   M-Shoes  "+ str(2500*MSho)+"   "+str(2500)+'\n')
                                if(WSh>0):
                                    file1.write(str(WSh) + "   W-Shirts  "+ str(1500*WSh)+"   "+str(1500)+'\n')
                                if(WTs>0):
                                    file1.write(str(WTs) + "   W-TShirts "+ str(1000*WTs)+"   "+str(1000)+'\n')
                                if(WJe>0):
                                    file1.write(str(WJe) + "   W-Jeans   "+ str(2500*WJe)+"   "+str(2500)+'\n')
                                if(WDe>0):
                                    file1.write(str(WDe) + "   W-Denim   "+ str(2000*WDe)+"   "+str(2000)+'\n')
                                if(WJc>0):
                                    file1.write(str(WJe) + "   W-Jacket  "+ str(5000*WJc)+"   "+str(5000)+'\n')
                                if(WSho>0):
                                    file1.write(str(WSho) + "   W-Shoes   "+ str(2500*WSho)+"   "+str(2500)+'\n')
                                if(KSh>0):
                                    file1.write(str(KSh) + "   K-Shirts  "+ str(1500*KSh)+"   "+str(1500)+'\n')
                                if(KTs>0):
                                    file1.write(str(KTs) + "   K-TShirts "+ str(1000*KTs)+"   "+str(1000)+'\n')
                                if(KJe>0):
                                    file1.write(str(KJe) + "   K-Jeans   "+ str(2500*KJe)+"   "+str(2500)+'\n')
                                if(KDe>0):
                                    file1.write(str(KDe) + "   K-Denim   "+ str(2000*KDe)+"   "+str(2000)+'\n')
                                if(KJc>0):
                                    file1.write(str(KJc) + "   K-Jacket  "+ str(5000*KJc)+"   "+str(5000)+'\n')
                                if(KSho>0):
                                    file1.write(str(KSho) + "   K-Shoes  "+ str(2500*KSho)+"   "+str(2500)+'\n')
                                if(Fty1>0):
                                    file1.write(str(Fty1) + "   F-Type1  "+ str(1500*Fty1)+"   "+str(1500)+'\n')
                                if(Fty2>0):
                                    file1.write(str(Fty2) + "   F-Type2  "+ str(2500*Fty2)+"   "+str(2500)+'\n')
                                if(Fty3>0):
                                    file1.write(str(Fty3) + "   F-Type3  "+ str(5500*Fty3)+"   "+str(5500)+'\n')
                                receipt=file1
                                file1.close()
                                myFile=open("ProOrders.txt",'r')
                                myList=[]
                                for i in myFile:
                                    i=i.rstrip()
                                    myList.append(i)
                                newList=myList[3:]
                                print("Name:{}\nAccount Number:{}".format(myList[0],myList[1]))
                                print()
                                print("Qty  Items   Price   Unit-Price")
                                print()
                                for i in newList:
                                    print(i)
                                print()
                                print("Total Bill:{}".format(myList[2]))
                                print()
                                print('Date and time of Checkout')
                                print()
                                now=datetime.datetime.now()
                                print(now.strftime("%Y-%m-%d %H:%M:%S"))
                                exit()  
                    else:#If password entered is wrong
                        os.system("cls")
                        print()
                        print("Wrong Password Entered")
                        print('Please Try Again')
                        print()                        
                        continue
                else:#if username entered wrong
                    os.system("cls")
                    print("User does'nt exist")
                    continue
    else:
        os.system("cls")
        print('You Entered an Invalid Number Try Again')
        print()
        continue