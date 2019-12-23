# Importa a biblioteca "random"
# https://docs.python.org/2/library/random.html
import random


print('''
=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================
''')

acaoInicial = input()



# Se a ação escolhida tiver sido "escolher um número aleatório"
if acaoInicial == '1':
    print('\nQuantos números quer?')
    drawTimes = input()
    print('\nQual o número mínimo a obter?')
    minNum = input()
    print('\nQual o número máximo a obter?')
    maxNum = input()
    print("""
======================
Número(s) obtidos:
""")
    # Executa o número de vezes que se pediu de acordo com drawTimes
    for i in range(0, int(drawTimes)):
        print(random.randint(int(minNum), int(maxNum)))
    print('======================')
    




ccList = ['cara', 'coroa'] # cara = 0 (1-1); coroa = 1 (2-1) // Used in lines: 69, 70.

# Se a ação escolhida tiver sido "mandar uma moeda ao ar"
if acaoInicial == '2':
    print('''
===================================
Cara ou coroa?

1: cara
2: coroa

(Escolha uma opção introduzindo
o número correspondente)
===================================
''')
    ccInput = input()

    # Faz a escolha na linha em baixo
    ccRandom = random.randint(1, 2)

    # Se a face escolhida corresponder com a face obtida, ganhou. Caso contrário, perdeu.
    if ccRandom == int(ccInput):
        ganhouPerdeuOutput = 'Ganhaste'
    else:
        ganhouPerdeuOutput = 'Perdeste'

    print('''
===============================''')
    print('Foi escolhida ' + ccList[int(ccInput)-1] + '.')
    print(ganhouPerdeuOutput + ', pois calhou ' + ccList[ccRandom-1] + '.')
    print('===============================')