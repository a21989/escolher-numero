# Importa a biblioteca "random"
# https://docs.python.org/2/library/random.html
import random


print("""

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================""")

acaoInicial = input("-> ")

def num():
	print("\n\n\n")
	print("===================================")
	print("Quantos números quer?")
	drawTimes = input("-> ")
	print("Qual o número mínimo a obter?")
	minNum = input("-> ")
	print("Qual o número máximo a obter?")
	maxNum = input("-> ")
	print("===================================\n\n")

	if int(minNum) > int(maxNum):
		print("\n[aviso] O NÚMERO MÍNIMO NÃO PODE SER MAIOR QUE O NÚMERO MÁXIMO\n")
		num()
	else:
		if int(drawTimes) > 1:
			n = "Números obtidos (" + str(drawTimes) + ")"
		else:
			n = "Número obtido"

		print("""
======================
""" + n + """:
""")
		# Executa o número de vezes que se pediu de acordo com drawTimes
		for _ in range(0, int(drawTimes)):
			print(random.randint(int(minNum), int(maxNum)))
		print("======================")
# end of num() function


def coin():
	print("""
===================================
Cara ou coroa?

1: cara
2: coroa

(Escolha uma opção introduzindo
o número correspondente)
===================================""")

	ccInput = input("-> ")

	# Faz a escolha na linha em baixo
	ccRandom = random.randint(1, 2)

	# Se a face escolhida corresponder com a face obtida, ganhou. Caso contrário, perdeu.
	if ccRandom == int(ccInput):
		ganhouPerdeuOutput = "Ganhaste"
	else:
		ganhouPerdeuOutput = "Perdeste"

	ccList = ["cara", "coroa"]

	print("""
===============================""")
	print("Foi escolhida " + ccList[int(ccInput)-1] + ".")
	print(ganhouPerdeuOutput + ", pois calhou " + ccList[ccRandom-1] + ".")
	print("===============================")
# end of coin() function


def main():
	if acaoInicial == "1":
		num()
	elif acaoInicial == "2":
		coin()

if __name__ == "__main__":
	main()