# Importa a biblioteca "random"
# https://docs.python.org/2/library/random.html
import random



# Dicionário de cara e coroa.
# 1 e 2 são iguais a cara e coroa, respetivamente. Isto não é uma boa explicação, mas é mais ou menos assim que funciona.
ccDict = {
    '1': 'cara',
    '2': 'coroa'
}



print('''
=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================
''')

acao = input()



# Se a ação escolhida tiver sido "escolher um número aleatório"
if acao == '1':
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
    


# Se a ação escolhida tiver sido "mandar uma moeda ao ar"
if acao == '2':
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
    # Faz a escolha na linha de baixo
    ccRandom = random.choice(['cara', 'coroa'])

    # Se a face escolhida (de acordo com o dicionário ccDict) corresponder com a face obtida, ganhou. Caso contrário, perdeu.
    if ccRandom == ccDict[ccInput]:
        ganhouperdeuOutput = 'Ganhaste'
    else:
        ganhouperdeuOutput = 'Perdeste'

    print('''
===============================''')
    print('Foi escolhida ' + ccDict[ccInput] + '.')
    print(ganhouperdeuOutput + ', pois calhou ' + ccRandom + '.')
    print('===============================')