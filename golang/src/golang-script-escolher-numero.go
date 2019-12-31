package main

import (
	"fmt"
)

var unsupportedInput bool = false

func start() {
	fmt.Println(`

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================`)

	if unsupportedInput == true {
		fmt.Println("\n\nINSIRA APENAS '1' OU '2'")
	}

	var acaoInicial string
	fmt.Scanln(&acaoInicial)

	switch acaoInicial {
	case "1":
		num()
		break
	case "2":
		coin()
		break
	}

	if acaoInicial != "1" && acaoInicial != "2" {
		if acaoInicial == "q" {
		} else {
			unsupportedInput = true
			start()
		}
	}
}

func num() {
	fmt.Println("11111111111111")
}

func coin() {
	fmt.Println("22222222222222")
}

func main() {

	start()
}
