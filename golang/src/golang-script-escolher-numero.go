package main

import (
	"fmt"
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
	fmt.Println("11111111111111")
}

func coin() {
	fmt.Println("22222222222222")
}

func main() {
	start()
}
