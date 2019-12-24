package main

import (
	"bufio"
	"fmt"
	"os"
)

var acaoInicial string

func main() {

	start()
}

func start() {
	fmt.Println(`

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================`)

	reader := bufio.NewReader(os.Stdin)
	acaoInicial, _ = reader.ReadString('\n')

	if acaoInicial == "1" {
		num()
	} else if acaoInicial == "2" {
		coin()
	} else {
		start()
	}
}

func num() {
	fmt.Println("11111111111111")
}

func coin() {
	fmt.Println("22222222222222")
}
