numbs = []
userInput = input('Syötä luku (tyhjä lopettaa): ')


while userInput != '':
    convert = int(userInput)
    numbs.append(convert)

    userInput = (input('Syötä uusi luku: '))

numbs.sort(reverse=True)

print(' \nViisi suurinta numeroasi:')
for i in range(5):
    print(numbs[i])
    i += 1


