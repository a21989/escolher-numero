package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

var unsupportedInput bool = false

const inputWarning1 string = "\n\n[aviso] INSIRA APENAS \"1\" OU \"2\"\n[dica]  INSIRA \"q\" PARA FECHAR O PROGRAMA (quit)"
const inputWarning2 string = "[aviso] O NÚMERO MÍNIMO NÃO PODE SER MAIOR QUE O NÚMERO MÁXIMO"

func start() {
	fmt.Println(`

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================`)

	if unsupportedInput == true {
		fmt.Println(inputWarning1)
	}

	var initialInput string
	fmt.Print("-> ")
	fmt.Scanln(&initialInput)

	if initialInput != "1" && initialInput != "2" {
		if initialInput == "q" {
		} else {
			unsupportedInput = true
			start()
		}
	} else {
		unsupportedInput = false
	}

	switch initialInput {
	case "1":
		num()
		break
	case "2":
		coin()
		break
	}

} // end of start function

func num() {
	fmt.Print("\n\n\n")
	var (
		drawTimes int
		minNum    int
		maxNum    int
		n         string
	)
	fmt.Println("===================================")
	fmt.Print("Quantos números quer?\n-> ")
	fmt.Scanln(&drawTimes)
	fmt.Print("Qual o número mínimo a obter?\n-> ")
	fmt.Scanln(&minNum)
	fmt.Print("Qual o número máximo a obter?\n-> ")
	fmt.Scanln(&maxNum)
	println("===================================\n\n")

	if drawTimes > 1 {
		n = "Números obtidos (" + strconv.Itoa(drawTimes) + ")"
	} else {
		n = "Número obtido"
	}

	if minNum > maxNum {
		print(inputWarning2)
		num()
	} else {
		fmt.Print(`======================
` + n + `:
`)

		for i := 1; i <= drawTimes; i++ {
			fmt.Println(rand.Intn(maxNum-minNum+1) + minNum)
		}

		fmt.Print("======================\n\n")
	}

} // end of num function

func coin() {
	coinArray := [2]string{
		"cara",
		"coroa",
	}

	fmt.Println(`

===================================
Cara ou coroa?

1: cara
2: coroa

(Escolha uma opção introduzindo
o número correspondente)
===================================`)

	var coinInput int
	fmt.Print("-> ")
	fmt.Scanln(&coinInput)

	var coinRandom int = rand.Intn(2) + 1

	var winlossOutput string

	if coinRandom == coinInput {
		winlossOutput = "Ganhaste"
	} else {
		winlossOutput = "Perdeste"
	}

	fmt.Print(`

===============================
Foi escolhida ` + coinArray[coinInput-1] + `.
` + winlossOutput + `, pois calhou ` + coinArray[coinRandom-1] + `.
===============================

`)

} // end of coin function

func main() {
	rand.Seed(time.Now().UnixNano())
	start()
} // end of main function
