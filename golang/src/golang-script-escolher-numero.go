package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

var unsupportedInput bool = false

const inputWarning string = "\n\nINSIRA APENAS \"1\" OU \"2\"\nINSIRA \"q\" PARA FECHAR O PROGRAMA (quit)"

func start() {
	fmt.Println(`

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================`)

	if unsupportedInput == true {
		fmt.Println(inputWarning)
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
	fmt.Print("Quantos números quer?\n-> ")
	fmt.Scanln(&drawTimes)
	fmt.Print("Qual o número mínimo a obter?\n-> ")
	fmt.Scanln(&minNum)
	fmt.Print("Qual o número máximo a obter?\n-> ")
	fmt.Scanln(&maxNum)

	if drawTimes > 1 {
		n = "Números obtidos (" + strconv.Itoa(drawTimes) + ")"
	} else {
		n = "Número obtido"
	}

	fmt.Print(`
======================
` + n + `:
`)

	rand.Seed(time.Now().UnixNano())

	for i := 1; i <= drawTimes; i++ {
		fmt.Println(rand.Intn(maxNum-minNum+1) + minNum)
	}

	fmt.Print("======================")
} // end of num function

func coin() {
	fmt.Println("22222222222222")
}

func main() {
	start()
} // end of coin function
