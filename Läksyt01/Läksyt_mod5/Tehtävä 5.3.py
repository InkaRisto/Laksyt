userInput = int(input('Syötä kokonaisluku: '))

def check_it(userInput):
    # Alempi ehto ei laske mukaan 2 tai 3, jotka molemmat alkulukuja
    if userInput == 2 or userInput == 3:
        return True
    else:
        for i in range(2, int(userInput/2)):
            if (userInput % i) == 0:
                return False
                # Mallinnettu netistä
                # Päästää läpi jotakin vääriä lukuja, esim. 15, 21, 55
            elif (userInput % 3) == 0:
                return False
            elif (userInput % 5) == 0:
                return False
            else:
                return True

if check_it(userInput) == True:
    print('Luku on alkuluku!')
else:
    print('Luku ei ole alkuluku.')
